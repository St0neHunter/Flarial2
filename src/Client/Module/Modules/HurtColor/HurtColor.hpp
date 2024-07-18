#pragma once

#include "../Module.hpp"
#include "../../../Events/EventHandler.hpp"
#include "HurtColorListener.hpp"


class HurtColor : public Module {

public:

    HurtColor() : Module("Hurt Color", "Change the color when you hit entities.", IDR_HURT_PNG, "") {

        Module::setup();

    };

    void onEnable() override {
        EventHandler::registerListener(new HurtColorListener("HurtColor", this));
        Module::onEnable();
    }

    void onDisable() override {
        EventHandler::unregisterListener("HurtColor");
        Module::onDisable();
    }

    void defaultConfig() override {
        if (settings.getSettingByName<std::string>("color") == nullptr)
            settings.addSetting("color", (std::string) "FFFFFF");
        if (settings.getSettingByName<bool>("color_rgb") == nullptr) settings.addSetting("color_rgb", false);
        if (settings.getSettingByName<float>("colorOpacity") == nullptr) settings.addSetting("colorOpacity", 0.65);
    }

    void settingsRender() override { }
};