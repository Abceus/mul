#pragma once
#include <functional>
#include <memory>
#include <vector>

template<typename... T>
class MulCallbackOwner {
public:
    MulCallbackOwner() = default;
    MulCallbackOwner(const std::function<void(T...)>& newCallback);
    void call(auto&&... args) const;
    void remove();

    bool isValid() const;
private:
    std::function<void(T...)> callback;
};

template<typename... T>
class MulCallbackCollection {
public:
    void call(auto&& ...) const;

    void addCallback(const std::weak_ptr<MulCallbackOwner<T...>>& newCallback);
    void removeCallback(const std::weak_ptr<MulCallbackOwner<T...>>& callbackForRemove);
private:
    mutable std::vector<std::weak_ptr<MulCallbackOwner<T...>>> callbacks;
};

template<typename... T>
MulCallbackOwner<T...>::MulCallbackOwner(const std::function<void(T...)>& newCallback) : callback(newCallback) {}

template<typename... T>
void MulCallbackOwner<T...>::call(auto&&... args) const {
    if(callback) {
        callback(std::forward<decltype(args)>(args)...);
    }
}

template<typename... T>
void MulCallbackOwner<T...>::remove() {
    callback = nullptr;
}

template<typename... T>
bool MulCallbackOwner<T...>::isValid() const {
    return callback != nullptr;
}

template<typename... T>
void MulCallbackCollection<T...>::call(auto&&... args) const {
    for(auto it = std::begin(callbacks); it != std::end(callbacks);) {
        if(auto lockedCallback = it->lock(); lockedCallback && lockedCallback->isValid()) {
            lockedCallback->call(std::forward<decltype(args)>(args)...);
            ++it;
        }
        else {
            it = callbacks.erase(it);
        }
    }
}    

template<typename... T>
void MulCallbackCollection<T...>::addCallback(const std::weak_ptr<MulCallbackOwner<T...>>& newCallback) {
    // TODO: 
    callbacks.emplace_back(newCallback);
}
   
template<typename... T> 
void MulCallbackCollection<T...>::removeCallback(const std::weak_ptr<MulCallbackOwner<T...>>& callbackForRemove) {
    auto found = std::find(std::begin(callbacks), std::end(callbacks), callbackForRemove);
    if(found != std::end(callbacks)) {
        callbacks.erase(found);
    }
}