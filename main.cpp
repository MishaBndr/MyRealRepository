#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));
    setlocale(LC_ALL, "Russian");
    ofstream file_for_breast("file_for_breas.txt");
    file_for_breast << "Жим штанги лёжа\nОтжимания";
    ofstream file_for_back("file_for_back.txt");
	file_for_back << "Тяга штанги в наклоне\nПодтягивания\nТяга верхнего блока к груди";
    ofstream file_for_legs("file_for_legs.txt");
	file_for_legs << "Приседания со штангой\nВыпады с гантелями\nЖим ногами в тренажёре";
    ofstream file_for_shoulders("file_for_shoulders.txt");
	file_for_shoulders << "Жим гантелей сидя\nПодъём гантелей через стороны\nТяга штанги к подбородку";
    ofstream file_for_hands("file_for_hands.txt");
	file_for_hands << "Сгибание рук со штангой\nФранцузский жим\nМолотковые сгибания с гантелями";
    ofstream file_for_abdominal_press("file_for_abdominal_press.txt");
	file_for_abdominal_press << "Скручивания на полу\nПодъём ног в висе\nПланка";
    
    if (!file_for_breast.is_open() || !file_for_back.is_open() || !file_for_legs.is_open() ||
        !file_for_shoulders.is_open() || !file_for_hands.is_open() || !file_for_abdominal_press.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    file_for_breast.close();
	file_for_back.close();
	file_for_legs.close();
	file_for_shoulders.close();
	file_for_hands.close();
	file_for_abdominal_press.close();

    cout << "Добро пожаловать в программу для отслеживания и изменений программ тренировок!" << endl;
    cout << "Для начала укажите ваш уровень мастерства, чтобы мы могли подобрать для вас подходящий график тренировок!";
    int level;
    cout << "\n1 - новичок\n2 - продвинутый\n3 - профессионал" << endl;
    cin >> level;
    while (level < 1 || level > 3) {
        cout << "Некорректный уровень мастерства!" << endl;
        cout << "Попробуйте ввести ещё раз: " << endl;
        cin >> level;
    }
        
    if (level == 1) {
        cout << "Отлично, вы новичок!" << endl << "В таком случае рекомендуе вам выбрать готовые шаблоны тренировок." << endl << "\033[35m«Факт из качалки!»\033[0m Если вы новичок, то лучше всего выбрать FullBody прокачку, а когда вы подниметесь до продвинутого уровня, можете переходить к split-технике!";
        cout << "Выберите подходящий вам шаблон:\n";
		int option;
		cout << "Вариант 1: Тренировки в понедельник, среду и пятницу." << endl << "Тип тренировки: Full Body" << endl;
        cout << "Вариант 2: Тренировки во вторник, четверг и субботу." << endl << "Тип тренировки: Full Body" << endl;
        cin >> option;
        while (option < 1 || option > 2) {
            cout << "Выберите один из предложенных вариантов!: " << endl;
            cin >> option;
        }
        if (option == 1 || option == 2) {
            cout << "Отлично! Ход тренировки построен! Предлагаемые упражнения:\n";
            cout << "\033[32mСпина:\033[0m\n";
            string line;
            ifstream file_for_back("file_for_back.txt");
            while (getline(file_for_back, line)) {
				cout << line << endl;
            }
            file_for_back.close();
			cout << "\033[32mГрудь:\033[0m\n";
            ifstream file_for_breast("file_for_breas.txt");
			while (getline(file_for_breast, line)) {
                cout << line << endl;
            }
			file_for_breast.close();
            cout << "\033[32mНоги:\033[0m\n";
			ifstream file_for_legs("file_for_legs.txt");
            while (getline(file_for_legs, line)) {
                cout << line << endl;
			}
            file_for_legs.close();
			cout << "\033[32mПлечи:\033[0m\n";
			ifstream file_for_shoulders("file_for_shoulders.txt");
            while (getline(file_for_shoulders, line)) {
				cout << line << endl;
            }
			file_for_shoulders.close();
			cout << "\033[32mРуки:\033[0m\n";
            ifstream file_for_hands("file_for_hands.txt");
            while (getline(file_for_hands, line)) {
                cout << line << endl;
            }
			file_for_hands.close();
			cout << "\033[32mПресс:\033[0m\n";
            ifstream file_for_abdominal_press("file_for_abdominal_press.txt");
            while (getline(file_for_abdominal_press, line)) {
                cout << line << endl;
			}
            file_for_abdominal_press.close();
        }
    }

    else if (level == 2) {
        cout << "Вы выбрали уровень продвинутый!" << endl;
        string valid_options[] = { "FullBody", "Split" };
        cout << "Вы желаете вести тренировки в режиме FullBody или педпочтёте Split?";

		string full_or_split;
		cin >> full_or_split;

        while (full_or_split != "FullBody" && full_or_split != "Split") {
            cout << "Некорректный ввод! Попробуйте ещё раз: ";
            cin >> full_or_split;
		}

		string days[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
        
        if (full_or_split == valid_options[0] || full_or_split == "fullbody") {
            cout << "Прекрасный выбор! " << valid_options[0] << " тренировки - универсальны всегда, теперь выберите дни, по которым хотите вести тренировки: ";
            
			string day1, day2, day3;
			cin >> day1 >> day2 >> day3;

            for (int i = 0; i < 7; i++) {
                while ((days[i] += 1) == day2 || (days[i] += 1) == day3) {
                    cout << "Внимание! Не рекомендуется провоить FullBody тренировки 2 или более дней подряд из-за риска перетрена! ";
                }
            }

            cout << "\nОтлично! Вы выбрали следующие дни для тренировок: " << day1 << ", " << day2 << ", " << day3 << ". Предлагаемые упражнения:\n";
            cout << "\033[32mСпина:\033[0m\n";
            string line;
            ifstream file_for_back("file_for_back.txt");
            while (getline(file_for_back, line)) {
                cout << line << endl;
            }
            file_for_back.close();
            cout << "\033[32mГрудь:\033[0m\n";
            ifstream file_for_breast("file_for_breas.txt");
            while (getline(file_for_breast, line)) {
                cout << line << endl;
            }
            file_for_breast.close();
            cout << "\033[32mНоги:\033[0m\n";
            ifstream file_for_legs("file_for_legs.txt");
            while (getline(file_for_legs, line)) {
                cout << line << endl;
            }
            file_for_legs.close();
            cout << "\033[32mПлечи:\033[0m\n";
            ifstream file_for_shoulders("file_for_shoulders.txt");
            while (getline(file_for_shoulders, line)) {
                cout << line << endl;
            }
            file_for_shoulders.close();
            cout << "\033[32mРуки:\033[0m\n";
            ifstream file_for_hands("file_for_hands.txt");
            while (getline(file_for_hands, line)) {
                cout << line << endl;
            }
            file_for_hands.close();
            cout << "\033[32mПресс:\033[0m\n";
            ifstream file_for_abdominal_press("file_for_abdominal_press.txt");
            while (getline(file_for_abdominal_press, line)) {
                cout << line << endl;
            }
            file_for_abdominal_press.close();
        }
        
    }

    else if (level == 3) {
        cout << "Вы выбрали уровень профессионал!" << endl;
    }
    
    return 0;
}