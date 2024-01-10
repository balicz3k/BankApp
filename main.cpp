#include "User.h"
#include "Database.h"

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
    //wyczyscPlikBinarny("/Users/balicz3k/Documents/BankApp/Users");
    Database D("/Users/balicz3k/Documents/BankApp/Users");
    D.load_data();
    cout<<D;
    cout<<D;
}