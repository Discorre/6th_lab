//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <thread>
//#include <Windows.h>
//#include <random>
//
//using namespace std;
//
//// Размеры поля
//const int width = 200;
//const int height = 49;
//
//// Функция для очистки экрана
//static void clear_screen() {
//    cout << "\033[2J\033[1;1H";  // ANSI escape код для очистки экрана
//}
//
//// Функция для отображения текущего состояния поля
//static void display_field(const vector<vector<int>>& field) {
//    clear_screen();
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0; j < width; ++j) {
//            if (field[i][j] == 1)
//                cout << "#";  // Живая клетка
//            else
//                cout << " ";  // Мёртвая клетка
//        }
//        cout << endl;
//    }
//}
//
//// Функция для вычисления следующего поколения
//static void next_generation(vector<vector<int>>& field) {
//    vector<vector<int>> next_field(height, vector<int>(width, 0));
//
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0; j < width; ++j) {
//            int neighbors = 0;
//            // Подсчёт количества соседей для каждой клетки
//            for (int ni = -1; ni <= 1; ++ni) {
//                for (int nj = -1; nj <= 1; ++nj) {
//                    if (ni == 0 && nj == 0)
//                        continue;  // Пропускаем текущую клетку
//                    int ni_wrap = (i + ni + height) % height; // Обработка граничных условий
//                    int nj_wrap = (j + nj + width) % width;   // Обработка граничных условий
//                    neighbors += field[ni_wrap][nj_wrap];
//                }
//            }
//            // Применение правил клеточного автомата
//            if (field[i][j] == 1) {
//                if (neighbors < 2 || neighbors > 3)
//                    next_field[i][j] = 0;  // Смерть из-за перенаселённости или одиночества
//                else
//                    next_field[i][j] = 1;  // Выживание
//            }
//            else {
//                if (neighbors == 3)
//                    next_field[i][j] = 1;  // Рождение новой клетки
//            }
//        }
//    }
//
//    // Копирование следующего поколения в текущее
//    field = next_field;
//}
//
//int main() {
//    // Инициализация поля
//    vector<vector<int>> field(height, vector<int>(width, 0));
//
//    //// Пример устойчивой фигуры: блок
//    field[5][5] = field[5][6] = field[6][5] = field[6][6] = 1;
//
//    //// Пример устойчивой фигуры: планер
//    field[29][130] = field[30][131] = field[31][129] = field[31][130] = field[31][131] = 1;
//    field[10][10] = field[11][11] = field[12][9] = field[12][10] = field[12][11] = 1;
//
//
//    field[20][120] = field[20][121] = field[21][120] = field[22][121] = field[23][122] = field[23][123] = 1;
//
//    field[5][5] = field[5][6] = field[6][5] = field[7][6] = field[8][7] = field[8][8] = 1;
//
//    // Планерное ружьё Госпера
//    field[5][21]= field[7][20] = field[4][19] = field[6][21] = field[5][22] = field[6][22] = 1;
//    field[5][31] = field[6][31] = field[6][32] = field[7][30] = field[5][32] = field[7][32] = field[8][30] = field[8][31] = field[9][31] = 1;
//    field[4][46] = field[5][46] = field[4][47] = field[5][47] = 1;
//
//    field[30][30] = field[31][30] = field[32][30] = field[31][31] = field[31][32] = 1;
//
//    // Анимация
//    for (int generation = 0; generation < 100; ++generation) {
//        display_field(field);
//        next_generation(field);
//        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//        Sleep(1000);
//    }
//
//    return 0;
//}
