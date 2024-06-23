import numpy as np
import time

# Размеры поля
width = 200
height = 49

# Функция для отображения текущего состояния поля
def display_field(field):
    for row in field:
        for cell in row:
            if cell == 1:
                print("#", end="")
            else:
                print(" ", end="")
        print()
    print("-" * width)

# Функция для вычисления следующего поколения
def next_generation(field):
    next_field = np.zeros_like(field)

    for i in range(height):
        for j in range(width):
            neighbors = np.sum(field[(i-1):(i+2), (j-1):(j+2)]) - field[i, j]
            if field[i, j] == 1:
                if neighbors < 2 or neighbors > 3:
                    next_field[i, j] = 0  # Смерть из-за перенаселённости или одиночества
                else:
                    next_field[i, j] = 1  # Выживание
            else:
                if neighbors == 3:
                    next_field[i, j] = 1  # Рождение новой клетки

    # Копирование следующего поколения в текущее
    np.copyto(field, next_field)

def main():
    # Инициализация поля
    field = np.zeros((height, width), dtype=int)

    # Примеры устойчивых фигур
    field[5:7, 5:7] = 1  # Блок
    field[29:32, 129:132] = 1  # Планер
    field[10:13, 9:12] = 1  # Планер
    field[20:24, 120:124] = 1  # Планер

    # Планерное ружьё Госпера
    field[4:7, 19:23] = 1
    field[5:8, 30:34] = 1
    field[6:8, 45:48] = 1
    field[30:33, 30:33] = 1

    # Анимация
    for generation in range(100):
        display_field(field)
        next_generation(field)
        time.sleep(1)

if __name__ == "__main__":
    main()
