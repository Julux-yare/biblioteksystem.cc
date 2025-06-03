

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Bok {
    std::string titel;
    std::string författare;
    int år;
};

void visaMeny() {
    std::cout << "\n--- Bibliotekssystem ---\n";
    std::cout << "1. Lägg till bok\n";
    std::cout << "2. Visa alla böcker\n";
    std::cout << "3. Sök efter bok\n";
    std::cout << "4. Avsluta\n";
    std::cout << "Välj ett alternativ: ";
}

void läggTillBok(std::vector<Bok>& bibliotek) {
    Bok nyBok;
    std::cin.ignore();
    std::cout << "Titel: ";
    std::getline(std::cin, nyBok.titel);
    std::cout << "Författare: ";
    std::getline(std::cin, nyBok.författare);
    std::cout << "Utgivningsår: ";
    std::cin >> nyBok.år;
    bibliotek.push_back(nyBok);
    std::cout << "Bok tillagd!\n";
}

void visaBöcker(const std::vector<Bok>& bibliotek) {
    if (bibliotek.empty()) {
        std::cout << "Inga böcker i systemet.\n";
        return;
    }
    std::cout << "\n--- Lista över böcker ---\n";
    for (const auto& bok : bibliotek) {
        std::cout << "Titel: " << bok.titel << "\n";
        std::cout << "Författare: " << bok.författare << "\n";
        std::cout << "År: " << bok.år << "\n";
        std::cout << "-----------------------\n";
    }
}

void sökBok(const std::vector<Bok>& bibliotek) {
    std::cin.ignore();
    std::string sökterm;
    std::cout << "Skriv titel eller författare att söka efter: ";
    std::getline(std::cin, sökterm);

    bool hittad = false;
    for (const auto& bok : bibliotek) {
        if (bok.titel.find(sökterm) != std::string::npos ||
            bok.författare.find(sökterm) != std::string::npos) {
            std::cout << "Titel: " << bok.titel << ", Författare: " << bok.författare << ", År: " << bok.år << "\n";
            hittad = true;
        }
    }

    if (!hittad)
        std::cout << "Ingen bok hittades.\n";
}

int main() {
    std::vector<Bok> bibliotek;
    int val;

    while (true) {
        visaMeny();
        std::cin >> val;

        switch (val) {
            case 1:
                läggTillBok(bibliotek);
                break;
            case 2:
                visaBöcker(bibliotek);
                break;
            case 3:
                sökBok(bibliotek);
                break;
            case 4:
                std::cout << "Avslutar programmet...\n";
                return 0;
            default:
                std::cout << "Ogiltigt val, försök igen.\n";
        }
    }
}
