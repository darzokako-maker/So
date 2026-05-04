#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include <jni.h>
#include <sys/mman.h>

// Offsetler
uintptr_t il2cpp_base = 0; 
#define OFF_AMMO 0x4A8BC50
#define OFF_RECOIL 0x498D268

bool show_menu = true;
bool ammo_active = false;

void patch_mem(uintptr_t addr, const char* hex, int len) {
    uintptr_t page_start = addr & ~(PAGE_SIZE - 1);
    mprotect((void*)page_start, PAGE_SIZE * 2, PROT_READ | PROT_WRITE | PROT_EXEC);
    memcpy((void*)addr, hex, len);
    mprotect((void*)page_start, PAGE_SIZE * 2, PROT_READ | PROT_EXEC);
}

void RenderMenu() {
    if (!show_menu) return;
    ImGui::Begin("Block Force VIP", &show_menu);
    if (ImGui::Checkbox("Sınırsız Mermi", &ammo_active)) {
        if (ammo_active) patch_mem(il2cpp_base + OFF_AMMO, "\x1F\x20\x03\xD5", 4);
    }
    ImGui::End();
}

