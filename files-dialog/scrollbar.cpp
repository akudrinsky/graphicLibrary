#include "../kudry/engine/settings.hpp"

int main(int argc, char* argv[]) {
    kudry::Engine::Init(argv[1]);

    kudry::Engine::Destroy();
}