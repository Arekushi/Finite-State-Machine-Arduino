#include <TenSeconds.h>

bool TenSeconds::decision(Car data) {
    return millis() >= 10000;
}
