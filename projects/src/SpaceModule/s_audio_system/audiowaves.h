#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {

    struct Wave {
    public:
        void push(float in) {
            m_time += in;
            if (m_time >= 1.0f)
            {
                m_time = m_time - std::floorf(m_time);
            }
        }
        virtual operator float() { return 0.f; }
    protected:
        float m_time = 0.f;
    };

    struct TriangleWave : public Wave {
    public:
        virtual operator float() override {
            float mult = m_time * 4.f;
            float rest = mult - std::floorf(mult);
            uint8_t mod = (uint8_t)mult % (uint8_t)4;
            if (mod == 0) {
                return rest;
            }
            else if (mod == 1) {
                return 1.f - rest;
            }
            else if (mod == 2) {
                return -rest;
            }
            else if (mod == 3) {
                return -1.f + rest;
            }
        }
    };

    struct SineWave : public Wave {
    public:
        virtual operator float() override {
            return std::sinf(m_time * 2.f * glm::pi<float>());
        }
    };

    struct SawWave : public Wave {
    public:
        virtual operator float() override {
            float wave = m_time * 2.f;
            if (wave >= 1.f)
            {
                return wave - 2.f;
            }
            return m_time;
        }
    };

    struct SquareWave : public Wave {
    public:
        virtual operator float() override {
            if (m_time < 0.5f)
            {
                return 1.f;
            }
            else {
                return -1.f;
            }
        }
    };
    using PulseWave = SquareWave;

}