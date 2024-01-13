#include "User.h"
#include "Database.h"
#include "MainInterface.h"
#include "Interface.h"

void wyczyscPlikBinarny(const std::string& nazwaPliku) {
    // Otwórz plik w trybie std::ios::trunc, co spowoduje usunięcie istniejącej zawartości
    std::ofstream plik(nazwaPliku, std::ios::binary | std::ios::trunc);

    // Sprawdź, czy plik został otwarty poprawnie
    if (plik.is_open()) {
        std::cout << "Plik " << nazwaPliku << " zostal wyczyszczony." << std::endl;
        // Zamknij plik
        plik.close();
    } else {
        std::cerr << "Blad otwierania pliku " << nazwaPliku << " do wyczyszczenia." << std::endl;
    }
}

int main(){
    MainInterface M;
    while(!M.get_Exit()){
        M.start_animation();
        M.show_menu();
        M.read_input();
        M.execute();
    }
}