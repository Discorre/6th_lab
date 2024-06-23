#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <random>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()

using namespace std;

const uint8_t s_box[256] = {
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
};

const uint8_t inv_s_box[256] = {
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
};

// ������� ��� ������ ������� �������� 4x4 � ����������������� �������
static void print_matrix(const array<array<uint8_t, 4>, 4>& matrix) {
    // ������ �� ������ ������ �������
    for (const auto& row : matrix) {
        // ������ �� ������� �������� ������
        for (const auto& element : row) {
            // ������ �������� � ����������������� ������� � �������� ������
            cout << hex << setw(2) << setfill('0') << static_cast<int>(element) << " ";
        }
        // ������ ������� ����� ������ ����� ������ ������ �������
        cout << endl;
    }
}

// ������� sub_bytes ��������� ���������� ������ ������� �������� ������� �� �������� �� s_box
static void sub_bytes(array<array<uint8_t, 4>, 4>& s) {
    // ������ �� ������ ������ �������
    for (int i = 0; i < 4; ++i) {
        // ������ �� ������� �������� ������
        for (int j = 0; j < 4; ++j) {
            // ������ �������� �������� �� �������� �� s_box �� ��� �������
            s[i][j] = s_box[s[i][j]];
        }
    }
}

// ������� inv_sub_bytes ��������� ���������� ������ ������� �������� ������� �� �������� �� inv_s_box
static void inv_sub_bytes(array<array<uint8_t, 4>, 4>& s) {
    // ������ �� ������ ������ �������
    for (int i = 0; i < 4; ++i) {
        // ������ �� ������� �������� ������
        for (int j = 0; j < 4; ++j) {
            // ������ �������� �������� �� �������� �� inv_s_box �� ��� �������
            s[i][j] = inv_s_box[s[i][j]];
        }
    }
}

// ������� shift_rows ��������� ����������� ����� ����� ������� �����
static void shift_rows(array<array<uint8_t, 4>, 4>& s) {
    // ����� ������ ������ �� ���� ������� �����
    swap(s[0][1], s[1][1]); // ������ ������� �������� (0,1) � (1,1)
    swap(s[0][1], s[2][1]); // ������ ������� �������� (0,1) � (2,1)
    swap(s[0][1], s[3][1]); // ������ ������� �������� (0,1) � (3,1)

    // ����� ������� ������ �� ��� �������� �����
    swap(s[0][2], s[2][2]); // ������ ������� �������� (0,2) � (2,2)
    swap(s[1][2], s[3][2]); // ������ ������� �������� (1,2) � (3,2)

    // ����� ��������� ������ �� ��� �������� �����
    swap(s[0][3], s[3][3]); // ������ ������� �������� (0,3) � (3,3)
    swap(s[0][3], s[2][3]); // ������ ������� �������� (0,3) � (2,3)
    swap(s[0][3], s[1][3]); // ������ ������� �������� (0,3) � (1,3)
}


// ������� inv_shift_rows ��� ��������� ������������ ������ ����� �������
static void inv_shift_rows(array<array<uint8_t, 4>, 4>& s) {
    swap(s[0][1], s[3][1]); // �������� 2-� ������� �� 1 ������� ����
    swap(s[0][1], s[2][1]); // �������� 2-� ������� �� 1 ������� ����
    swap(s[0][1], s[1][1]); // �������� 2-� ������� �� 1 ������� ����

    swap(s[0][2], s[2][2]); // �������� 3-� ������� �� 2 ������� ����
    swap(s[1][2], s[3][2]); // �������� 3-� ������� �� 2 ������� ����

    swap(s[0][3], s[1][3]); // �������� 4-� ������� �� 3 ������� ����
    swap(s[0][3], s[2][3]); // �������� 4-� ������� �� 3 ������� ����
    swap(s[0][3], s[3][3]); // �������� 4-� ������� �� 3 ������� ����
}

// ������� add_round_key ��� ���������� �������� ������� s � �������� ����� k
static void add_round_key(array<array<uint8_t, 4>, 4>& s, const array<array<uint8_t, 4>, 4>& k) {
    for (int i = 0; i < 4; ++i) { // �������� �� ������ ������ �������
        for (int j = 0; j < 4; ++j) { // �������� �� ������� �������� ������
            s[i][j] ^= k[i][j]; // ��������� XOR �������� ������� s � ��������������� ��������� ������� k
        }
    }
}

// ������� xtime ��� ��������� ����� a �� 2 � ���� �����
static uint8_t xtime(uint8_t a) {
    return (a << 1) ^ ((a & 0x80) ? 0x1B : 0x00); // �������� a ����� �� 1 ��� � ��������� XOR � 0x1B, ���� ������� ��� ��� ���������� (11011 = 0x1B = x^4 + x^3 + x + 1)
}

// ������� mix_single_column ��� ���������� ������ ������� �������
static void mix_single_column(array<uint8_t, 4>& a) {
    uint8_t t = a[0] ^ a[1] ^ a[2] ^ a[3]; // ��������� ����� ���� ��������� �������
    uint8_t u = a[0]; // ��������� �������������� �������� ������� ��������
    a[0] ^= t ^ xtime(a[0] ^ a[1]); // ��������� ������ �������
    a[1] ^= t ^ xtime(a[1] ^ a[2]); // ��������� ������ �������
    a[2] ^= t ^ xtime(a[2] ^ a[3]); // ��������� ������ �������
    a[3] ^= t ^ xtime(a[3] ^ u); // ��������� ��������� �������
}

// ������� mix_columns ��� ���������� ���� �������� �������
static void mix_columns(array<array<uint8_t, 4>, 4>& s) {
    for (int i = 0; i < 4; ++i) { // �������� �� ������� ������� �������
        mix_single_column(s[i]); // ��������� ���������� � ������� �������
    }
}

// ������� inv_mix_columns ��� ��������� ���������� ���� �������� �������
static void inv_mix_columns(array<array<uint8_t, 4>, 4>& s) {
    for (int i = 0; i < 4; ++i) { // �������� �� ������� ������� �������
        uint8_t u = xtime(xtime(s[i][0] ^ s[i][2])); // ��������� u ��� xtime ������ ��� ��������� 0 � 2
        uint8_t v = xtime(xtime(s[i][1] ^ s[i][3])); // ��������� v ��� xtime ������ ��� ��������� 1 � 3
        s[i][0] ^= u; // ��������� u � �������� 0
        s[i][1] ^= v; // ��������� v � �������� 1
        s[i][2] ^= u; // ��������� u � �������� 2
        s[i][3] ^= v; // ��������� v � �������� 3
    }

    mix_columns(s); // ��������� ������� ���������� ��������
}

// ������� bytes2matrix ��� ����������� ������� ���� � ������� 4x4
static array<array<uint8_t, 4>, 4> bytes2matrix(const vector<uint8_t>& bytes) {
    array<array<uint8_t, 4>, 4> matrix{}; // ������� ������ �������
    for (int i = 0; i < 16; ++i) { // �������� �� ������� �����
        matrix[i / 4][i % 4] = bytes[i]; // ��������� ������� �������
    }
    return matrix; // ���������� �������
}

// ������� matrix2bytes ��� ����������� ������� 4x4 � ������ ����
static vector<uint8_t> matrix2bytes(const array<array<uint8_t, 4>, 4>& matrix) {
    vector<uint8_t> bytes(16); // ������� ������ ���� �������� 16
    for (int i = 0; i < 16; ++i) { // �������� �� ������� �������� �������
        bytes[i] = matrix[i / 4][i % 4]; // ��������� ������ ������� �� �������
    }
    return bytes; // ���������� ������ ����
}


// ����� AES
class AES {
public:
    // ����������� ������, ����������� ������-���� � ����������� ��� �� ��������� ������
    explicit AES(const vector<uint8_t>& master_key) {
        assert(master_key.size() == 16); // ���������, ��� ������ ������-����� ���������� 16 ����
        key_matrices = expand_key(master_key); // ��������� ������-���� �� ��������� ������
    }

    // ������� ���������� ������ ����� ������
    vector<uint8_t> encrypt_block(const vector<uint8_t>& plaintext) {
        assert(plaintext.size() == 16); // ���������, ��� ������ ������� ������ ���������� 16 ����
        auto state = bytes2matrix(plaintext); // ����������� ������� ������ � �������
        add_round_key(state, key_matrices[0]); // ��������� ��������� ��������� ����
        print_matrix(state);
        // ��������� 9 ������� ��������������: SubBytes, ShiftRows, MixColumns, AddRoundKey
        for (int i = 1; i < 10; ++i) {
            sub_bytes(state);
            shift_rows(state);
            mix_columns(state);
            add_round_key(state, key_matrices[i]);
        }
        // ��������� ��������� ����� �������������� ��� MixColumns
        sub_bytes(state);
        shift_rows(state);
        add_round_key(state, key_matrices[10]);
        return matrix2bytes(state); // ���������� ������������� ������
    }

    // ������� ������������ ������ ����� ������
    vector<uint8_t> decrypt_block(const vector<uint8_t>& ciphertext) {
        assert(ciphertext.size() == 16); // ���������, ��� ������ ������������� ������ ���������� 16 ����
        auto state = bytes2matrix(ciphertext); // ����������� ������������� ������ � �������
        add_round_key(state, key_matrices[10]); // ��������� ��������� ��������� ����
        inv_shift_rows(state); // �������� ����� �����
        inv_sub_bytes(state); // �������� ������ ������
        // ��������� 9 �������� ������� ��������������: AddRoundKey, InvMixColumns, InvShiftRows, InvSubBytes
        for (int i = 9; i > 0; --i) {
            add_round_key(state, key_matrices[i]);
            inv_mix_columns(state);
            inv_shift_rows(state);
            inv_sub_bytes(state);
        }
        add_round_key(state, key_matrices[0]); // ��������� ��������� ��������� ����
        return matrix2bytes(state); // ���������� ������������� ������
    }

    void write_to_file(const string& filename, const string& data) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Data appended to file: " << filename << endl;
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }


    // ������� ��� ��������� ���������� ����� � ������ ��� � ����
    void generate_random_key(const string& filename) {
        random_device rd;
        uniform_int_distribution<> dis(0, 256);
        vector<uint8_t> random_key(16); // ������� ������ ��� �������� ���������� ����� �������� 16 ����
        generate(random_key.begin(), random_key.end(), []() { // ��������� ������ ���������� ����������
            return static_cast<uint8_t>(rand() % 256); // ��������� ����� �� 0 �� 255
            });
        key_matrices = expand_key(random_key); // ��������� ��������� ���� �� ��������� ������
        write_key2file(random_key, filename); // ���������� ���� � ����
  
    }

    // ����������� ������� ��� ������ ����� � ����
    static void write_key2file(const vector<uint8_t>& key, const string& filename) {
        ofstream outfile(filename, ios::binary); // ��������� ���� ��� ������ �������� ������
        outfile.write(reinterpret_cast<const char*>(key.data()), key.size()); // ���������� ���� � ����
        outfile.close(); // ��������� ����
    }

    // ������� ��� ������ ��������� ������
    void print_key_matrices() {
        cout << "Key Matrices:" << endl;
        for (size_t i = 0; i < key_matrices.size(); i++) { // �������� �� ������� ���������� �����
            cout << "Round " << i << ":" << endl;
            print_matrix(key_matrices[i]); // �������� ������� �������� ���������� �����
            cout << endl;
        }
    }

    // ������� ��� ������ ��������� ������, ������������� � �������������� ������ � ����
    void write_data_to_file(const string& filename, const vector<uint8_t>& encrypted, const vector<uint8_t>& decrypted, const string& decrypted_str) {
        ofstream outfile(filename);
        if (!outfile.is_open()) {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }

        // ������������� ������ ������ � ����������������� �������
        outfile << hex << setfill('0');

        // ���������� ��������� �����
        for (size_t i = 0; i < key_matrices.size(); i++) {
            outfile << "Round " << i << ":" << endl;
            for (const auto& row : key_matrices[i]) {
                for (int val : row) {
                    // ���������� ������ ������� ������� � ���� � ����������������� �������
                    outfile << setw(2) << val << " ";
                }
                outfile << endl;
            }
            outfile << endl;
        }

        // ���������� ������������� ������
        outfile << "Bytes Ciphertext: ";
        for (auto byte : encrypted)
            outfile << setw(2) << (int)byte << " ";
        outfile << endl;

        // ���������� �������������� ������
        outfile << "Bytes Decrypted: ";
        for (uint8_t byte : decrypted) {
            outfile << setw(2) << (int)byte << " ";
        }
        outfile << endl;
        outfile << "Decrypted text: " << decrypted_str << endl;

        outfile.close();
        cout << "Data has been written to " << filename << endl;
    }




private:
    array<array<array<uint8_t, 4>, 4>, 11> key_matrices{}; // ������ �������� ������ �������� 11, ������������ ��� ����������

    // ������� expand_key ��������� ������-���� �� ��������� ������
    static array<array<array<uint8_t, 4>, 4>, 11> expand_key(const vector<uint8_t>& master_key) {
        array<array<array<uint8_t, 4>, 4>, 11> key_schedule{}; // �������������� ������ ��������� ������
        array<array<uint8_t, 4>, 4> key_columns{}; // ������� ��� �������� ������� ������-�����

        // ��������� ������� key_columns ������� �� ������-�����
        for (int i = 0; i < 16; ++i) {
            key_columns[i / 4][i % 4] = master_key[i];
        }

        // ������ �������� ������� ����� key_columns
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                key_schedule[0][i][j] = key_columns[i][j];
            }
        }

        uint8_t rcon = 1; // ������������� Rcon ��� ��������� ��������� ��������

        // ��������� ��������� �������� ������
        for (int round = 1; round < 11; ++round) {
            array<uint8_t, 4> temp = key_schedule[static_cast<array<array<array<uint8_t, 4Ui64>, 4Ui64>, 11Ui64>::size_type>(round) - 1][3]; // ����� ��������� ������� ���������� �������

            // Circular shift (����������� �����)
            uint8_t t = temp[0];
            for (int i = 0; i < 3; ++i) {
                temp[i] = temp[static_cast<array<uint8_t, 4Ui64>::size_type>(i) + 1];
            }
            temp[3] = t;

            // S-Box transformation (������ ������ �� ������� �����)
            for (int i = 0; i < 4; ++i) {
                temp[i] = s_box[temp[i]];
            }

            // XOR � ��������� ���������� (Rcon)
            temp[0] ^= rcon;
            rcon = xtime(rcon);

            // ��������� �������� ������� �������� ������
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    key_schedule[round][i][j] = key_schedule[static_cast<array<array<array<uint8_t, 4Ui64>, 4Ui64>, 11Ui64>::size_type>(round) - 1][i][j] ^ temp[j];
                }
                temp = key_schedule[round][i]; // ��������� temp ��� ��������� ��������
            }
        }

        return key_schedule; // ���������� ������ ��������� ������
    }
};

    // �������������� ������ � ������ ������
    static vector<uint8_t> string_to_bytes(const string& input) {
        return vector<uint8_t>(input.begin(), input.end()); // ���������� ����������� ������� ��� �������������� ������ � ������ ������
    }

    // �������������� ������� ������ � ������
    static string bytes_to_string(const vector<uint8_t>& input) {
        return string(input.begin(), input.end()); // ���������� ����������� ������ ��� �������������� ������� ������ � ������
    }


    int main() {
        setlocale(LC_ALL, "ru");

        // ������ �������������
        string key_str = "qwertybetaqwerty";
        string plaintext_str = "betakillmarkbruhbetakillmarkbruh"; // ����� ������ ���� ������� 16 ��� ����� �������

        // �������������� ����� � ������� ������
        vector<uint8_t> key = string_to_bytes(key_str);
        vector<uint8_t> plaintext = string_to_bytes(plaintext_str);

        AES aes(key);

        // ����������� ��������� ���� � �������� ��� � ����
        aes.generate_random_key("random_key.txt");

        // ����� ���� ��������������� ������
        aes.print_key_matrices();

        // ���������� ������� �� 16 ����
        vector<uint8_t> encrypted;
        for (size_t i = 0; i < plaintext.size(); i += 16) {
            vector<uint8_t> block(plaintext.begin() + i, plaintext.begin() + i + 16);
            vector<uint8_t> encrypted_block = aes.encrypt_block(block);
            encrypted.insert(encrypted.end(), encrypted_block.begin(), encrypted_block.end());
        }

        // ������������� ������� �� 16 ����
        vector<uint8_t> decrypted;
        for (size_t i = 0; i < encrypted.size(); i += 16) {
            vector<uint8_t> block(encrypted.begin() + i, encrypted.begin() + i + 16);
            vector<uint8_t> decrypted_block = aes.decrypt_block(block);
            decrypted.insert(decrypted.end(), decrypted_block.begin(), decrypted_block.end());
        }

        // �������������� �������� ������ ������� � ������
        string ciphertext_str = bytes_to_string(encrypted);
        string decrypted_str = bytes_to_string(decrypted);

        // ����� �������������� � ��������������� ������
        cout << "Bytes Ciphertext: ";
        for (auto byte : encrypted)
            cout << hex << setw(2) << setfill('0') << (int)byte << " ";
        cout << endl;

        cout << "Bytes Decrypted: ";
        for (uint8_t byte : decrypted) {
            printf("%02x ", byte);
        }
        cout << endl;

        cout << "Decrypted text: " << decrypted_str << endl;

        aes.write_data_to_file("data.txt", encrypted, decrypted, decrypted_str); // ������ ��������� ������, ������������� � �������������� ������ � ����

        // ��������, ��� �������������� ����� ��������� � ��������
        //assert(plaintext == decrypted_str);

    return 0;
}
