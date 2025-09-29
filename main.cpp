#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

//cout << "\033[30mЧерный текст\033[0m" << endl;
//cout << "\033[31mКрасный текст\033[0m" << endl;
//cout << "\033[32mЗеленый текст\033[0m" << endl;
//cout << "\033[33mЖелтый текст\033[0m" << endl;
//cout << "\033[34mСиний текст\033[0m" << endl;
//cout << "\033[35mПурпурный текст\033[0m" << endl;
//cout << "\033[36mБирюзовый текст\033[0m" << endl;
//cout << "\033[37mБелый текст\033[0m" << endl;
//cout << "\033[90mЯрко-черный (серый) текст\033[0m" << endl;
//cout << "\033[91mЯрко-красный текст\033[0m" << endl;

void showExercises(const string& groupName, const string& fileName) {
    cout << "\033[32m" << groupName << ":\033[0m\n";
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла: " << fileName << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

// добавление упражнения в файл
void addExerciseToFile(const string& fileName) {
    ofstream fout(fileName, ios::app);
    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла для записи: " << fileName << endl;
        return;
    }

    cin.ignore();
    cout << "Введите упражнение, которое хотите добавить: ";
    string exercise;
    getline(cin, exercise);

    fout << endl << exercise;
    fout.close();

    cout << "Упражнение успешно добавлено!" << endl;
}

void chooseADay(int choise) {
    string days[7] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
    cout << "\nВыбранный день для тренировки: " << days[choise - 1] << endl;
}

void isCorrectMuscule(int& num) {
    while (num < 1 || num > 6) {
        cout << "Некорректный выбор! Выберите из предложенных групп: ";
        cin >> num;
    }
}

void isCorrectDay(int& num) {
    while (num < 1 || num > 7) {
        cout << "Некорректный выбор! Выберите из предложенных дней: ";
        cin >> num;
    }
}

void printBack() {
    showExercises("Спина", "file_for_back.txt");
};
void printBreas() {
    showExercises("Грудь", "file_for_breas.txt");
};
void printLegs() {
    showExercises("Ноги", "file_for_legs.txt");
};
void printShoulders() {
    showExercises("Плечи", "file_for_shoulders.txt");
};
void printHands() {
    showExercises("Руки", "file_for_hands.txt");
};
void printAbdominalPress() {
    showExercises("Пресс", "file_for_abdominal_press.txt");
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //ofstream file1("file_for_back.txt");
    //ofstream file2("file_for_breas.txt");
    //ofstream file3("file_for_legs.txt");
    //ofstream file4("file_for_shoulders.txt");
    //ofstream file5("file_for_hands.txt");
    //ofstream file6("file_for_abdominal_press.txt");

    //file1 << "Подтягивания\nТяга верхнего блока\nТяга гантели в наклоне";
    //file2 << "Отжимания\nЖим штанги лёжа\nГрудной жим с гантелями";
    //file3 << "Приседания с собственным весом\nЖим ногами\nВыпады с гантелями";
    //file4 << "Подъем гантелей через стороны\nЖим гантелей сидя\nПодъем штанги или гантелей перед собой";
    //file5 << "Отжимания на брусьях\nСгибания рук с гантелями\nФранцузский жим";
    //file6 << "Планка\nСкручивания\nПодъемы ног в висе";

    //file1.close();
    //file2.close();
    //file3.close();
    //file4.close();
    //file5.close();
    //file6.close();

    cout << "\033[91mДобро пожаловать в программу для отслеживания и изменений программ тренировок!" << endl;

    int choice_menu;
    do {
        cout << "\n\033[91m===ГЛАВНОЕ МЕНЮ===\033[0m\n";
        cout << "1 - Выбрать план тренировок\n";
        cout << "2 - Добавить упражнения в файлы\n";
        cout << "3 - Создать свой план\n";
        cout << "0 - Выход\n\n";
        cout << "\033[90mВаш выбор: \033[0m";
        cin >> choice_menu;
        if (choice_menu == 1) {

            cout << "\n\033[35mДля начала укажите ваш уровень мастерства, чтобы мы могли подобрать для вас подходящий график тренировок!\033[0m";
            int level;
            cout << "\n\n\033[32m1 - новичок\n\n\033[33m2 - продвинутый\n\n" << endl;
            cout << "\033[90mВаш выбор: \033[0m";
            cin >> level;
            while (level < 1 || level > 3) {
                cout << "Некорректный уровень мастерства!" << endl;
                cout << "Попробуйте ввести ещё раз: " << endl;
                cin >> level;
            }//beginner section
            if (level == 1) {
                cout << "\033[36mОтлично, вы новичок!" << endl << "В таком случае рекомендуем вам выбрать готовые шаблоны тренировок." << endl << "\033[35m«Факт из качалки!»\033[36m Если вы новичок, то лучше всего выбрать FullBody прокачку, а когда вы подниметесь до продвинутого уровня, можете переходить к split-технике!";
                cout << "\033[36mВыберите подходящий вам шаблон:\n\n";
                int option;
                cout << "\033[36mВариант 1: Тренировки в понедельник, среду и пятницу. Тип тренировки: Full Body\n";
                cout << "\n\033[36mВариант 2: Тренировки во вторник, четверг и субботу. Тип тренировки: Full Body\n";
                cin >> option;
                while (option < 1 || option > 2) {
                    cout << "\nВыберите один из предложенных вариантов!: \n";
                    cin >> option;
                }
                if (option == 1 || option == 2) {
                    cout << "\n\033[36mОтлично! Ход тренировок построен! Предлагаемые упражнения:\033[0m\n";
                    showExercises("Спина", "file_for_back.txt");
                    showExercises("Грудь", "file_for_breas.txt");
                    showExercises("Ноги", "file_for_legs.txt");
                    showExercises("Плечи", "file_for_shoulders.txt");
                    showExercises("Руки", "file_for_hands.txt");
                    showExercises("Пресс", "file_for_abdominal_press.txt");
                }
            }
            //advanced section
            else if (level == 2) {
                void (*arr_of_functions[6])() = { printBack, printBreas, printLegs, printShoulders, printHands, printAbdominalPress };
                string valid_options[] = { "FullBody", "Split" };
                cout << "Желаете вести тренировки в режиме FullBody или педпочтёте Split?";
                string full_or_split;
                cout << "\n\n\033[32m== FullBody ==\033[0m - универсальный вариант, когда в один день тренируются все группы мышц.\n\n\033[33m== Split ==\033[0m - продвинутый вариант, когда в один день тренируется одна или несколько групп мышц.\n\n";
                cout << "\033[90mВаш выбор: \033[0m";
                cin >> full_or_split;

                while (full_or_split != "FullBody" && full_or_split != "Split" && full_or_split != "fullbody" && full_or_split != "split") {
                    cout << "Некорректный ввод! Попробуйте ещё раз: ";
                    cin >> full_or_split;
                }
                //fullbody option
                if (full_or_split == valid_options[0] || full_or_split == "fullbody") {

                    cout << "\n\033[36mПрекрасный выбор! " << valid_options[0] << " тренировки - универсальны всегда, теперь выберите дни, по которым хотите вести тренировки: \033[0m";
                    int choose_a_day1, choose_a_day2, choose_a_day3;
                    cout << "\n\nУ вас есть выбор из следующих дней: \n\n\033[32m== 1 - Понедельник ==\033[0m\n\n\033[33m== 2 - Вторник ==\033[0m\n\n\033[34m== 3 - Среда ==\033[0m\n\n\033[35m== 4 - Четверг ==\033[0m\n\n\033[36m== 5 - Пятница ==\033[0m\n\n\033[91m== 6 - Суббота ==\033[0m\n\n\033[31m== 7 - Воскресенье ==\033[0m\n\n";
                    cout << "\n\nВведите номер первого дня тренировки (1-7): ";
                    cin >> choose_a_day1;

                    cout << "\n\nВведите номер второго дня тренировки (1-7): ";
                    cin >> choose_a_day2;

                    cout << "\n\nВведите номер третьего дня тренировки (1-7): ";
                    cin >> choose_a_day3;

                    cout << "\n\033[31mОтлично! Ваш план тренировок на всю неделю готов: \033[0m\n";
                    cout << "Выбранные вами дни: ";
                    chooseADay(choose_a_day1);
                    chooseADay(choose_a_day2);
                    chooseADay(choose_a_day3);
                    cout << "\033[31mПредлагаемые упражнения:\033[0m\n";
                    showExercises("Спина", "file_for_back.txt");

                    showExercises("Грудь", "file_for_breas.txt");

                    showExercises("Ноги", "file_for_legs.txt");

                    showExercises("Плечи", "file_for_shoulders.txt");

                    showExercises("Руки", "file_for_hands.txt");

                    showExercises("Пресс", "file_for_abdominal_press.txt");

                }
                //split option
                else if (full_or_split == valid_options[1] || full_or_split == "split") {
                    cout << "\n\033[36mПрекрасный выбор! " << valid_options[1] << " тренировки - для тех, кто хочет большего! Для начала выберите дни, по которым хотите вести тренировки, а затем выберите группы мышц:\033[0m\n";
                    cout << "\n\nУ вас есть выбор из классических крупномышечных групп:\n\033[32m\n==Спина== - 1\n\n\033[33m==Грудь== - 2\n\n\033[34m==Ноги== - 3\n\n\033[35m==Плечи== - 4\n\n\033[36m==Руки= - 5\n\n\033[91m==Пресс== - 6\n\n\033[0m";
                    int choose_a_day1, choose_a_day2, choose_a_day3;
                    cout << "У вас есть выбор из следующих дней: \n\n\033[32m== 1 - Понедельник ==\033[0m\n\n\033[33m== 2 - Вторник ==\033[0m\n\n\033[34m== 3 - Среда ==\033[0m\n\n\033[35m== 4 - Четверг ==\033[0m\n\n\033[36m== 5 - Пятница ==\033[0m\n\n\033[91m== 6 - Суббота ==\033[0m\n\n\033[31m== 7 - Воскресенье ==\033[0m\n\n";
                    
                    cout << "Введите номер первого дня тренировки (1-7): ";

                    cin >> choose_a_day1;
                    isCorrectDay(choose_a_day1);
                    cout << "\nТеперь выберите группу мышц, с которой хотите работать в этот день: ";

                    int choice1;
                    cin >> choice1;
                    isCorrectMuscule(choice1);
                    cout << "Введите номер второго дня тренировки (1-7): ";

                    cin >> choose_a_day2;
                    isCorrectDay(choose_a_day2);
                    cout << "\nТеперь выберите группу мышц, с которой хотите работать в этот день: ";

                    int choice2;
                    cin >> choice2;
                    isCorrectMuscule(choice2);
                    cout << "Введите номер третьего дня тренировки (1-7): ";

                    cin >> choose_a_day3;
                    isCorrectDay(choose_a_day3);
                    cout << "\nТеперь выберите группу мышц, с которой хотите работать в этот день: ";

                    int choice3;
                    cin >> choice3;
                    isCorrectMuscule(choice3);
                    cout << "\n\033[31mОтлично! Ваш план тренировок на всю неделю готов: \033[0m\n";

                    chooseADay(choose_a_day1);
                    arr_of_functions[choice1 - 1]();

                    chooseADay(choose_a_day2);
                    arr_of_functions[choice2 - 1]();

                    chooseADay(choose_a_day3);
                    arr_of_functions[choice3 - 1]();
                }
            }
        }
        else if (choice_menu == 2) {
        cout << "\nВыберите группу мышц:\n";
        cout << "1 - Спина\n";
        cout << "2 - Грудь\n";
        cout << "3 - Ноги\n";
        cout << "4 - Плечи\n";
        cout << "5 - Руки\n";
        cout << "6 - Пресс\n";
        int choose_group;
        cin >> choose_group;

        switch (choose_group) {
        case 1: addExerciseToFile("file_for_back.txt"); break;
        case 2: addExerciseToFile("file_for_breas.txt"); break;
        case 3: addExerciseToFile("file_for_legs.txt"); break;
        case 4: addExerciseToFile("file_for_shoulders.txt"); break;
        case 5: addExerciseToFile("file_for_hands.txt"); break;
        case 6: addExerciseToFile("file_for_abdominal_press.txt"); break;
        default: cout << "Некорректный выбор!" << endl;
        }
        }
        else if (choice_menu == 3) {
        int choose_variant;
        cout << "\033[91m==меню==\033[0m";
        cout << "\n1 - Просмотреть ваш план тренировок\n";
        cout << "2 - Добавить свой план тренировок\n";
        cin >> choose_variant;
        if (choose_variant == 1) {
            string line;
            fstream myfile("my_plan.txt", ios::in);
            if (!myfile.is_open()) {
                cerr << "Ошибка открытия файла: my_plan.txt" << endl;
                return 1;
            }
            cout << "\nВаш план тренировок:\n";
            while (getline(myfile, line)) {
                cout << line << endl;
            }
            myfile.close();
        }
        else if (choose_variant == 2) {
            fstream myfile("my_plan.txt", ios::app);
            if (!myfile.is_open()) {
                cerr << "Ошибка открытия файла для записи: my_plan.txt" << endl;
                return 1;
            }
            cin.ignore();
            cout << "Введите ваш план тренировок: ";
            string user_plan;
            getline(cin, user_plan);
            myfile << endl << user_plan;
            myfile.close();
            cout << "Ваш план успешно сохранён в файл my_plan.txt!" << endl;
        }

        }
        else if (choice_menu == 0) {
        cout << "Выход из программы. До встречи!\n";
        }

        else {
        cout << "Некорректный ввод, попробуйте ещё раз.\n";
        }

    } while (choice_menu != 0);
    return 0;
}
