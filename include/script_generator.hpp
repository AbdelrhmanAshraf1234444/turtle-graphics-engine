#include <iostream>
#include <fstream>
#include <string>

void runScriptGenerator()
{
    std::ofstream file("test.turtle");

    if(!file.is_open())
    {
        std::cerr << "Error opening file!\n";
        return;
    }

    // =========================
    //?   Canvas Size
    // =========================
    int width, height;

    std::cout << "Enter Canvas Width: ";
    std::cin >> width;

    std::cout << "Enter Canvas Height: ";
    std::cin >> height;

    file << "size w=" << width << " h=" << height << "\n";

    // =========================
    //?   Pen Color
    // =========================
    std::cout << "\nSelect Pen Color:\n";
    std::cout << "1) Black\n2) White\n3) Red\n4) Green\n5) Blue\n6) Yellow\n";

    int penChoice;
    std::cin >> penChoice;

    std::string penColor;

    switch(penChoice)
    {
        case 1: penColor = "black" ; break;
        case 2: penColor = "white" ; break;
        case 3: penColor = "red"   ; break;
        case 4: penColor = "green" ; break;
        case 5: penColor = "blue"  ; break;
        case 6: penColor = "yellow"; break;
        default: penColor = "black"; break;
    }

    // =========================
    //?  Background Color
    // =========================
    std::cout << "\nSelect Background Color:\n";
    std::cout << "1) Black\n2) White\n3) Red\n4) Green\n5) Blue\n6) Yellow\n";

    int bgChoice;
    std::cin >> bgChoice;

    std::string bgColor;

    switch(bgChoice)
    {
        case 1: bgColor = "black"   ; break;
        case 2: bgColor = "white"   ; break;
        case 3: bgColor = "red"     ; break;
        case 4: bgColor = "green"   ; break;
        case 5: bgColor = "blue"    ; break;
        case 6: bgColor = "yellow"  ; break;
        default: bgColor = "white"  ; break;
    }

    file << "color pen=" << penColor
         << " bg=" << bgColor << "\n";

    // =========================
    //?  Start Position
    // =========================
    int startChoice;
    std::cout << "\nStart Pen State:\n";
    std::cout << "1) Pen Down\n2) Pen Up\n";
    std::cout << "Choice: ";
    std::cin >> startChoice;

    int startX, startY;

    std::cout << "Enter Start X: ";
    std::cin >> startX;

    std::cout << "Enter Start Y: ";
    std::cin >> startY;

    if(startChoice == 1)
        file << "pen down " << startX << " " << startY << "\n";
    else
        file << "pen up " << startX << " " << startY << "\n";

    // =========================
    //?  Commands Menu
    // =========================
    std::cout << "\nSelect Commands:\n";
    std::cout << "1) Move Forward\n";
    std::cout << "2) Move Backward\n";
    std::cout << "3) Turn Right\n";
    std::cout << "4) Turn Left\n";
    std::cout << "5) Pen Down\n";
    std::cout << "6) Pen Up\n";
    std::cout << "0) Finish --> pen up \n";

    while(true)
    {
        int choice;

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if(choice == 0)
            break;

        switch(choice)
        {
            case 1:
            {
                double value;
                std::cout << "Distance: ";
                std::cin >> value;
                file << "move forward " << value << "\n";
                break;
            }

            case 2:
            {
                double value;
                std::cout << "Distance: ";
                std::cin >> value;
                file << "move backward " << value << "\n";
                break;
            }

            case 3:
            {
                double value;
                std::cout << "Degrees: ";
                std::cin >> value;
                file << "turn right " << value << "\n";
                break;
            }

            case 4:
            {
                double value;
                std::cout << "Degrees: ";
                std::cin >> value;
                file << "turn left " << value << "\n";
                break;
            }

            case 5:
                file << "pen down\n";
                break;

            case 6:
                file << "pen up\n";
                break;

            default:
                std::cout << "Invalid choice!\n";
        }
    }

    file.close();

    std::cout << "\nScript saved successfully to test.turtle \n";

}