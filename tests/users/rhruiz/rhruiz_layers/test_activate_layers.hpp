#include "test_fixture.hpp"

class ActivateLayers : public TestFixture {
    protected:
    void setup_trns(layer_t layers[], uint8_t count, uint8_t cols);
};
