// m411YO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct SensorData {
    int id;
    int value;
} structValue;

typedef struct SensorReadout {
    structValue* pValue;
    struct SensorReadout* pPrev;
    struct SensorReadout* pNext;
} structData;

class CliMgr {
    // Yaron Fanger
    private:
        bool running = true;
        structData* pStart;

    // Yaron Fanger
    public:
        // Yaron Fanger
        int get_action() {

            int input;
            int range[2] = { 1, 5 };

            while (true) {
                printf("\033[33mChoose one of the following actions: \033[39m\n");
                printf("(1)%20s", "generate list\n");
                printf("(2)%20s", "delete list\n");
                printf("(3)%20s", "sort list (DESC)\n");
                printf("(4)%20s", "sort lsit (ASC)\n");
                printf("(5)%20s", "exit\n\n");

                printf("\033[36mEnter action index: \033[39m");
                scanf_s("%i", &input);

                if (input >= range[0] && input <= range[1]) {
                    return input;
                }
                else {
                    printf("\n--------------------------------------------------------------------------");
                    printf("\n\033[31mThe action you enter dose no exist, please enter a valid input\033[39m");
                    printf("\n--------------------------------------------------------------------------\n\n");
                }
            }
        }

        // Yaron Fanger
        void draw_interface() {
            system("CLS");
            printf("MMMMMMMM               MMMMMMMM  1111111     1111111   \n");
            printf("M:::::::M             M:::::::M 1::::::1    1::::::1   \n");
            printf("M::::::::M           M::::::::M1:::::::1   1:::::::1   \n");
            printf("M:::::::::M         M:::::::::M111:::::1   111:::::1   \n");
            printf("M::::::::::M       M::::::::::M   1::::1      1::::1   \n");
            printf("M:::::::::::M     M:::::::::::M   1::::1      1::::1   \n");
            printf("M:::::::M::::M   M::::M:::::::M   1::::1      1::::1   \n");
            printf("M::::::M M::::M M::::M M::::::M   1::::l      1::::l   \n");
            printf("M::::::M  M::::M::::M  M::::::M   1::::l      1::::l   \n");
            printf("M::::::M   M:::::::M   M::::::M   1::::l      1::::l   \n");
            printf("M::::::M    M:::::M    M::::::M   1::::l      1::::l   \n");
            printf("M::::::M               M::::::M111::::::111111::::::111\n");
            printf("M::::::M               M::::::M1::::::::::11::::::::::1\n");
            printf("M::::::M               M::::::M1::::::::::11::::::::::1\n");
            printf("MMMMMMMM               MMMMMMMM111111111111111111111111\n\n");
            printf("--------------------------------------------------------------------------\n\n");
            printf("M11 project by:\n-> Yaron Fanger\n-> Ott Hendrik\n\n");
            printf("--------------------------------------------------------------------------\n");
        }

        // Yaron Fanger
        void input_mgr(int input) {
            switch (input) {
                case 1:
                    this->generate_array();
                    break;
                case 2:
                    this->delete_array();
                    break;
                case 3:
                    this->sort_array(true);
                    break;
                case 4:
                    this->delete_array();
                    break;
                case 5:
                    printf_s("exititng service, thank you!");
                    this->running = false;
                    break;
            }
        }

        // Yaron Fanger
        void start_loop() {
            while (this->running) {
                this->draw_interface();
                int input = this->get_action();
                this->input_mgr(input);
            }
        };

        // Yaron Fanger
        void generate(int amount) {
            structData* pStart = NULL;
            structData* pCurrent = NULL;
            structData* pPrevious = NULL;

            for (int i = 0; i < amount; i++) {
                // Assigning memory to struct variable emp 
                pCurrent = (structData*)malloc(sizeof(structData));
                pCurrent->pValue = (structValue*)malloc(sizeof(structValue));

                // Assigning values
                pCurrent->pValue->id = 1000 * rand();
                pCurrent->pValue->value = 100000 * rand();

                if (pPrevious == NULL) {
                    pStart = pCurrent;
                }
                else {
                    pCurrent->pPrev = pPrevious;
                    pCurrent->pPrev->pNext = pCurrent;
                }

                pPrevious = pCurrent;

                if (i + 1 == amount) {
                    pCurrent->pPrev = pPrevious;
                    pCurrent->pPrev->pNext = pCurrent;
                }
            }

            this->pStart = pStart;
            
        };

        // Yaron Fanger
        void generate_array() {
            // generate list and assign it to class varible list
            printf("generating array...");
            int amount = 0;

            printf("How many elements do you want tor create?\n");
            printf("\033[36mEnter amount: \033[39m");
            scanf_s("%i", &amount);
            this->generate(amount);
        }

        // Yaron Fanger
        void dislay_array() {
            int amount;
            int iindex = 0;
            printf("How many elements do you want to display?\n");
            printf("\033[36mEnter amount: \033[39m");
            scanf_s("%i", &amount);

            for (structData* p = this->pStart; amount > iindex || p == NULL; p = p->pNext) {
                iindex++;
                printf("ID: %i\n", p->pValue->id);
            }
        }

        void delete_array() {
            // delete list and remove assignment to list varible
            printf("deleting list...");
        }

        void sort_array(bool desc = false) {
            if (desc) {
                // sort list desc after process assign value to list varible
                printf("sorting list desc...");
            }
            else {
                // sort list acs
                printf("sorting list acs...");
            }
        }
};

int main()
{
    CliMgr cliMgr;
    cliMgr.generate_array();
    cliMgr.dislay_array();
}
