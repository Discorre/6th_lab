import numpy as np  # Импортируем библиотеку NumPy для работы с матрицами и векторами

def print_matrix(matrix):
    for row in matrix:  # Итерируемся по строкам матрицы
        print("|", end="")  # Выводим вертикальную черту для отделения столбцов
        for i, elem in enumerate(row):  # Итерируемся по элементам строки
            print(f"{elem:7.2f}", end="")  # Выводим элемент с выравниванием по правому краю и 2 знаками после запятой
            if i == len(row) - 2:  # Если дошли до предпоследнего элемента строки
                print("|", end="")  # Выводим вертикальную черту для отделения столбцов
        print("|")  # Переходим на новую строку после окончания вывода строки матрицы

def gauss_elimination(matrix):
    n = len(matrix)  # Получаем размерность матрицы

    # Forward Elimination (Прямой ход)
    for i in range(n):  # Итерируемся по строкам матрицы
        # Нормализуем строку (делаем единичный элемент на главной диагонали)
        matrix[i] /= matrix[i][i]
        # Вычитаем текущую строку из всех нижерасположенных строк
        for j in range(i + 1, n):
            matrix[j] -= matrix[j][i] * matrix[i]

    # Backward Substitution (Обратный ход)
    for i in range(n - 1, 0, -1):  # Итерируемся по строкам в обратном порядке, начиная с предпоследней строки
        for j in range(i - 1, -1, -1):  # Итерируемся по всем строкам выше текущей строки
            # Вычитаем текущую строку из всех вышерасположенных строк
            matrix[j] -= matrix[j][i] * matrix[i]

    # Возвращаем решение системы (последний столбец матрицы)
    return [row[-1] for row in matrix]

def main():
    np.set_printoptions(precision=2)  # Устанавливаем опции вывода NumPy для двух знаков после запятой

    M, N, P = -0.77, 0.16, 1.12  # Инициализируем коэффициенты системы уравнений

    # Исходная система линейных уравнений в виде матрицы
    matrix = np.array([
        [M, -0.04, 0.21, -18, -1.24],
        [0.25, -1.23, N, -0.09, P],
        [-0.21, N, 0.8, -0.13, 2.56],
        [0.15, -1.31, 0.06, P, M]
    ], dtype=float)

    print("Система уравнений в виде матрицы:")
    print_matrix(matrix)  # Выводим матрицу на экран

    # Решаем систему уравнений методом Гаусса
    solution = gauss_elimination(matrix.copy())

    print("\nРешение системы:")
    for i, x in enumerate(solution):
        print(f"x{i+1} = {x:.4f}")  # Выводим решения уравнений с округлением до четырех знаков после запятой

if __name__ == "__main__":
    main()
