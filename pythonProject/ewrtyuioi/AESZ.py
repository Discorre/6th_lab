s_box = (
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16,
)

inv_s_box = (
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D,
)

def sub_bytes(s):
    """
    Заменяет каждый элемент матрицы `s` на соответствующее значение из S-Box.
    """
    for i in range(4):
        for j in range(4):
            s[i][j] = s_box[s[i][j]]


def inv_sub_bytes(s):
    """
    Выполняет обратную операцию замены для каждого элемента матрицы `s`, используя обратную S-Box.
    """
    for i in range(4):
        for j in range(4):
            s[i][j] = inv_s_box[s[i][j]]


def shift_rows(s):
    """
    Сдвигает строки матрицы `s` влево на один элемент, два элемента и три элемента соответственно.
    """
    s[0][1], s[1][1], s[2][1], s[3][1] = s[1][1], s[2][1], s[3][1], s[0][1]
    s[0][2], s[1][2], s[2][2], s[3][2] = s[2][2], s[3][2], s[0][2], s[1][2]
    s[0][3], s[1][3], s[2][3], s[3][3] = s[3][3], s[0][3], s[1][3], s[2][3]


def inv_shift_rows(s):
    """
    Обратная операция для сдвига строк: первая строка остаётся на месте, вторая сдвигается на один элемент вправо,
    третья на два элемента вправо, четвёртая на три элемента вправо.
    """
    s[0][1], s[1][1], s[2][1], s[3][1] = s[3][1], s[0][1], s[1][1], s[2][1]
    s[0][2], s[1][2], s[2][2], s[3][2] = s[2][2], s[3][2], s[0][2], s[1][2]
    s[0][3], s[1][3], s[2][3], s[3][3] = s[1][3], s[2][3], s[3][3], s[0][3]


def add_round_key(s, k):
    """
    Выполняет операцию XOR для каждого элемента матрицы `s` с соответствующим элементом матрицы ключа `k`.
    """
    for i in range(4):
        for j in range(4):
            s[i][j] ^= k[i][j]


def xtime(a):
    """
    Возвращает результат умножения числа `a` на 2 в поле Галуа.
    """
    return (((a << 1) ^ 0x1B) & 0xFF) if (a & 0x80) else (a << 1)


def mix_single_column(a):
    """
    Применяет операцию MixColumns к одному столбцу матрицы `a`.
    """
    t = a[0] ^ a[1] ^ a[2] ^ a[3]
    u = a[0]
    a[0] ^= t ^ xtime(a[0] ^ a[1])
    a[1] ^= t ^ xtime(a[1] ^ a[2])
    a[2] ^= t ^ xtime(a[2] ^ a[3])
    a[3] ^= t ^ xtime(a[3] ^ u)


def mix_columns(s):
    """
    Применяет операцию MixColumns ко всей матрице `s`.
    """
    for i in range(4):
        mix_single_column(s[i])


def inv_mix_columns(s):
    """
    Применяет обратную операцию MixColumns ко всей матрице `s`.
    """
    for i in range(4):
        u = xtime(xtime(s[i][0] ^ s[i][2]))
        v = xtime(xtime(s[i][1] ^ s[i][3]))
        s[i][0] ^= u
        s[i][1] ^= v
        s[i][2] ^= u
        s[i][3] ^= v

    mix_columns(s)

r_con = (
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,
    0x80, 0x1B, 0x36, 0x6C, 0xD8, 0xAB, 0x4D, 0x9A,
    0x2F, 0x5E, 0xBC, 0x63, 0xC6, 0x97, 0x35, 0x6A,
    0xD4, 0xB3, 0x7D, 0xFA, 0xEF, 0xC5, 0x91, 0x39,
)


def bytes2matrix(text):
    """ Преобразует массив из 16 байт в матрицу 4x4. """
    return [list(text[i:i + 4]) for i in range(0, len(text), 4)]


def matrix2bytes(matrix):
    """ Преобразует матрицу 4x4 в массив из 16 байт. """
    return bytes(sum(matrix, []))


def xor_bytes(a, b):
    """ Возвращает новый массив байтов с элементами, выполненными по побитовому исключающему ИЛИ. """
    return bytes(i ^ j for i, j in zip(a, b))


def split_blocks(message, block_size=16, require_padding=True):
    """
    Разделяет сообщение на блоки указанного размера, обычно 16 байт (128 бит) для AES.

    Аргументы:
        message: Входное сообщение, которое нужно разбить.
        block_size: Размер каждого блока в байтах. По умолчанию 16 байт.
        require_padding: Если True, длина сообщения должна быть кратна размеру блока. По умолчанию True.

    Возвращает:
        Список блоков, каждый из которых имеет размер `block_size` и содержит разделенное сообщение.
    """
    assert len(message) % block_size == 0 or not require_padding
    return [message[i:i + block_size] for i in range(0, len(message), block_size)]


class AES:
    """
    Класс для шифрования AES-128 с режимом CBC и дополнением PKCS#7.

    Это сырая реализация AES без растяжения ключа или управления IV.
    Если вам это не нужно, используйте `encrypt` и `decrypt`.
    """
    rounds_by_key_size = {16: 10, 24: 12, 32: 14}  # Определяем количество раундов в зависимости от размера ключа
    def __init__(self, master_key):
        """
        Инициализирует объект с заданным ключом.
        """
        assert len(master_key) in AES.rounds_by_key_size  # Проверяем, что длина ключа соответствует одному из вариантов
        self.n_rounds = AES.rounds_by_key_size[len(master_key)]  # Определяем количество раундов на основе размера ключа
        self._key_matrices = self._expand_key(master_key)  # Расширяем ключ

    def _expand_key(self, master_key):
        """
        Расширяет и возвращает список матриц ключей для данного master_key.
        """
        key_columns = bytes2matrix(master_key)  # Преобразуем ключ в матрицу
        iteration_size = len(master_key) // 4  # Размер итерации

        i = 1
        while len(key_columns) < (self.n_rounds + 1) * 4:
            word = list(key_columns[-1])  # Получаем последнее слово ключа

            if len(key_columns) % iteration_size == 0:  # Выполняем это каждую итерацию
                word.append(word.pop(0))  # Циклический сдвиг
                word = [s_box[b] for b in word]  # Применяем S-BOX
                word[0] ^= r_con[i]  # XOR с R-CON
                i += 1
            elif len(master_key) == 32 and len(key_columns) % iteration_size == 4:  # Выполняем только для 256-битных ключей
                word = [s_box[b] for b in word]  # Применяем S-BOX

            word = xor_bytes(word, key_columns[-iteration_size])  # XOR с предыдущим словом
            key_columns.append(word)  # Добавляем новое слово в ключ

        return [key_columns[4*i : 4*(i+1)] for i in range(len(key_columns) // 4)]  # Группируем слова ключа в матрицы

    def encrypt_block(self, plaintext):
        """
        Шифрует один блок длиной 16 байт.
        """
        assert len(plaintext) == 16  # Проверяем длину блока

        plain_state = bytes2matrix(plaintext)  # Преобразуем блок в матрицу

        add_round_key(plain_state, self._key_matrices[0])  # Добавляем начальный раундовый ключ

        for i in range(1, self.n_rounds):  # Проводим раунды шифрования
            sub_bytes(plain_state)  # Заменяем байты
            shift_rows(plain_state)  # Сдвигаем строки
            mix_columns(plain_state)  # Применяем MixColumns
            add_round_key(plain_state, self._key_matrices[i])  # Добавляем раундовый ключ

        sub_bytes(plain_state)  # Последний раунд: заменяем байты
        shift_rows(plain_state)  # Последний раунд: сдвигаем строки
        add_round_key(plain_state, self._key_matrices[-1])  # Последний раунд: добавляем последний раундовый ключ

        return matrix2bytes(plain_state)  # Преобразуем матрицу в байты

    def decrypt_block(self, ciphertext):
        """
        Расшифровывает отдельный блок длиной 16 байт.
        """
        assert len(ciphertext) == 16  # Проверяем длину блока

        cipher_state = bytes2matrix(ciphertext)  # Преобразуем блок в матрицу

        add_round_key(cipher_state, self._key_matrices[-1])  # Начинаем с последнего раундового ключа
        inv_shift_rows(cipher_state)  # Инвертируем сдвиги строк
        inv_sub_bytes(cipher_state)  # Инвертируем замену байтов

        for i in range(self.n_rounds - 1, 0, -1):  # Проводим обратные раунды
            add_round_key(cipher_state, self._key_matrices[i])  # Добавляем обратный раундовый ключ
            inv_mix_columns(cipher_state)  # Инвертируем MixColumns
            inv_shift_rows(cipher_state)  # Инвертируем сдвиги строк
            inv_sub_bytes(cipher_state)  # Инвертируем замену байтов

        add_round_key(cipher_state, self._key_matrices[0])  # Добавляем первый раундовый ключ

        return matrix2bytes(cipher_state)  # Преобразуем матрицу в байты

    def encrypt_ofb(self, plaintext, iv):
        """
        Шифрует `plaintext` с использованием режима OFB и вектора инициализации (iv).
        """
        assert len(iv) == 16  # Проверяем длину IV

        blocks = []  # Список для хранения зашифрованных блоков
        previous = iv  # Инициализируем предыдущий блок начальным вектором
        for plaintext_block in split_blocks(plaintext, require_padding=False):
            # Шифрование в режиме OFB: plaintext_block XOR encrypt(previous)
            block = self.encrypt_block(previous)  # Шифруем предыдущий блок
            ciphertext_block = xor_bytes(plaintext_block, block)  # XOR с зашифрованным предыдущим блоком
            blocks.append(ciphertext_block)  # Добавляем зашифрованный блок в список
            previous = block  # Обновляем предыдущий блок

        return b''.join(blocks)  # Объединяем зашифрованные блоки в один поток байтов

    def decrypt_ofb(self, ciphertext, iv):
        """
        Расшифровывает `ciphertext` с использованием режима OFB и вектора инициализации (iv).
        """
        assert len(iv) == 16  # Проверяем длину IV

        blocks = []  # Список для хранения расшифрованных блоков
        previous = iv  # Инициализируем предыдущий блок начальным вектором
        for ciphertext_block in split_blocks(ciphertext, require_padding=False):
            # Расшифрование в режиме OFB: ciphertext XOR encrypt(previous)
            block = self.encrypt_block(previous)  # Шифруем предыдущий блок
            plaintext_block = xor_bytes(ciphertext_block, block)  # XOR с зашифрованным предыдущим блоком
            blocks.append(plaintext_block)  # Добавляем расшифрованный блок в список
            previous = block  # Обновляем предыдущий блок

        return b''.join(blocks)  # Объединяем расшифрованные блоки в один поток байтов


import os  # Импортируем модуль os для работы с операционной системой
from hashlib import pbkdf2_hmac  # Импортируем функцию pbkdf2_hmac из модуля hashlib для генерации ключа
from hmac import new as new_hmac, compare_digest  # Импортируем функции new_hmac и compare_digest из модуля hmac

AES_KEY_SIZE = 16  # Задаем размер ключа AES
HMAC_KEY_SIZE = 16  # Задаем размер ключа HMAC
IV_SIZE = 16  # Задаем размер вектора инициализации (IV)

SALT_SIZE = 16  # Задаем размер соли
HMAC_SIZE = 32  # Задаем размер HMAC-хэша

def get_key_iv(password, salt, workload=100000):  # Определяем функцию get_key_iv
    """
    Получает ключ и вектор инициализации AES, а также ключ HMAC
    путем растяжения пароля с использованием PBKDF2.
    """
    stretched = pbkdf2_hmac('sha256', password, salt, workload, AES_KEY_SIZE + IV_SIZE + HMAC_KEY_SIZE)
    aes_key, stretched = stretched[:AES_KEY_SIZE], stretched[AES_KEY_SIZE:]
    hmac_key, stretched = stretched[:HMAC_KEY_SIZE], stretched[HMAC_KEY_SIZE:]
    iv = stretched[:IV_SIZE]
    return aes_key, hmac_key, iv

def encrypt(key, plaintext, workload=100000):  # Определяем функцию encrypt
    """
    Шифрует `plaintext` с использованием `key` методом AES-128 в режиме OFB,
    выполняет проверку целостности с помощью HMAC и растягивает ключ с помощью PBKDF2.
    """
    if isinstance(key, str):  # Проверяем, является ли ключ строкой
        key = key.encode('utf-8')  # Если да, преобразуем его в байтовый формат
    if isinstance(plaintext, str):  # Проверяем, является ли текст строкой
        plaintext = plaintext.encode('utf-8')  # Если да, преобразуем его в байтовый формат

    salt = os.urandom(SALT_SIZE)  # Генерируем случайную соль
    key, hmac_key, iv = get_key_iv(key, salt, workload)  # Получаем ключи и вектор инициализации
    ciphertext = AES(key).encrypt_ofb(plaintext, iv)  # Шифруем текст
    hmac = new_hmac(hmac_key, salt + ciphertext, 'sha256').digest()  # Вычисляем HMAC для проверки целостности
    assert len(hmac) == HMAC_SIZE  # Проверяем размер HMAC-хэша

    return hmac + salt + ciphertext  # Возвращаем зашифрованный текст вместе с HMAC и солью

def decrypt(key, ciphertext, workload=100000):  # Определяем функцию decrypt
    """
    Расшифровывает `ciphertext` с использованием `key` методом AES-128 в режиме OFB,
    выполняет проверку целостности с помощью HMAC и растягивает ключ с помощью PBKDF2.
    """

    assert len(ciphertext) % 16 == 0, "Шифротекст должен состоять из полных 16-байтовых блоков."

    assert len(ciphertext) >= 32, """
    Длина шифротекста должна быть не менее 32 байт (16 байт соли + 16 байт блока). Чтобы
    шифрования или расшифровки отдельных блоков используйте `AES(ключ).decrypt_block(ciphertext)`.
    """

    if isinstance(key, str):  # Проверяем, является ли ключ строкой
        key = key.encode('utf-8')  # Если да, преобразуем его в байтовый формат

    hmac, ciphertext = ciphertext[:HMAC_SIZE], ciphertext[HMAC_SIZE:]  # Разделяем HMAC и зашифрованный текст
    salt, ciphertext = ciphertext[:SALT_SIZE], ciphertext[SALT_SIZE:]  # Разделяем соль и зашифрованный текст
    key, hmac_key, iv = get_key_iv(key, salt, workload)  # Получаем ключи и вектор инициализации

    expected_hmac = new_hmac(hmac_key, salt + ciphertext, 'sha256').digest()  # Вычисляем ожидаемый HMAC
    assert compare_digest(hmac, expected_hmac), 'Ciphertext corrupted or tampered.'  # Проверяем целостность текста

    return AES(key).decrypt_ofb(ciphertext, iv)  # Расшифровываем текст

def main():

    password = "Pentagonvzlomatp"  # Задаем пароль
    message = "Slava Rossii yra"  # Задаем сообщение

    encrypted = encrypt(password, message)  # Шифруем сообщение
    decrypted = decrypt(password, encrypted)  # Расшифровываем сообщение

    print("Original message:", message)  # Выводим исходное сообщение
    print("Encrypted message:", encrypted[1:])  # Выводим зашифрованное сообщение
    print("Decrypted message:", decrypted)  # Выводим расшифрованное сообщение


if __name__ == "__main__":
    main()  # Вызываем функцию main, если скрипт запущен как основной
