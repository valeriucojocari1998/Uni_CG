#include <iostream>
#include <GL/freeglut.h>

// Function declarations for each homework and point
void run_tema1_point1();
void run_tema1_point2();
void run_tema2_point1();
void run_tema2_point2();
void run_tema2_point3();
void run_tema3_square();
void run_tema3_solar();
void run_tema4_square();
void run_proiect1();

int main(int argc, char** argv) {
    int choice;
    bool running = true;

    while (running) {
        std::cout << "Choose homework to run:" << std::endl;
        std::cout << "1. Tema 1 Triunghi RGB" << std::endl;
        std::cout << "2. Tema 1 Triunghi RGB + Text" << std::endl;
        std::cout << "3. Tema 2 Multe figuri" << std::endl;
        std::cout << "4. Tema 2 Triunghiuri multiple" << std::endl;
        std::cout << "5. Tema 2 Hexagon" << std::endl;
        std::cout << "6. Tema 3 Square" << std::endl;
        std::cout << "7. Tema 3 Solar System" << std::endl;
        std::cout << "8. Tema 4 Textured Square" << std::endl;
        std::cout << "9. Proiect 1" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                run_tema1_point1();
                break;
            case 2:
                run_tema1_point2();
                break;
            case 3:
                run_tema2_point1();
                break;
            case 4:
                run_tema2_point2();
                break;
            case 5:
                run_tema2_point3();
                break;
            case 6:
                run_tema3_square();
                break;
            case 7:
                run_tema3_solar();
                break;
            case 8:
                run_tema4_square();
                break;
            case 9:
                run_proiect1();
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}
