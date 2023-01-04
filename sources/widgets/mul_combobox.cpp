#include "widgets/mul_combobox.h"
#include <imgui.h>

void MulCombobox::onDraw() {
    ImGui::PushID(this);
    if(ImGui::BeginCombo("##combobox", variants.empty() ? "" : variants[currentIndex].c_str())) {
        for(auto i = 0; i < variants.size(); ++i) {
            const auto& variant = variants[i];
            if(ImGui::Selectable(variant.c_str())) {
                if(currentIndex != i) {
                    currentIndex = i;
                    callbackCollection.call(i, variant);
                }
            }
        }
        ImGui::EndCombo();
    }
    ImGui::PopID();
}

std::shared_ptr<MulCallbackOwner<size_t, std::string>> MulCombobox::addChangeValueCallback(const std::function<void(size_t, std::string)>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<size_t, std::string>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}

void MulCombobox::setVariants(const std::vector<std::string>& newVariants) {
    variants = newVariants;
}

std::string MulCombobox::getValue() const {
    if(variants.empty()) {
        return "";
    }

    return variants[currentIndex];
}

size_t MulCombobox::getIndex() const {
    return currentIndex;
}