#include <iostream>
#include <string>
using namespace std;

//InventoryTokoKomputer
//C030324062_STRUCT
//git branch -M main
//git push -u origin main
//git add C030324062_STRUCT.cpp
//git commit -m "BLA BLA BLA"

struct toko{
    int id;
    string nama;
    string kategori;
    string harga;
    int stok;
    toko* next;
};

toko* listBarang(int id, string nama, string kategori, string harga, int stok) {
    toko* barangBaru=new toko;
    barangBaru->id=id;
    barangBaru->nama=nama;
    barangBaru->kategori=kategori;
    barangBaru->harga=harga;
    barangBaru->stok=stok;
    barangBaru->next=nullptr;
    return barangBaru;
}

void tampilkanBarang(toko* head){ 
    if(head==nullptr){
        cout << "Daftar barang kosong." << endl;
        return;
    }
    toko* temp=head;
    while(temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Kategori: " << temp->kategori << endl;
        cout << "Harga: " << temp->harga << endl;
        cout << "Stok: " << temp->stok << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}

void tambahBarang(toko*& head) {
  int id;
  string nama, kategori, harga;
  int stok;
    cout << "Masukkan ID: ";
    cin >> id;
    cin.ignore();
    toko* cek = head;
    while (cek != nullptr) {
        if (cek->id == id) {
            cout << "ID sudah digunakan! Barang tidak ditambahkan.\n";
            return;
        }
        cek = cek->next;
    }
    cout << "Nama: ";
    getline(cin, nama);
    cout << "Kategori: ";
    getline(cin, kategori);
    cout << "Harga: ";
    getline(cin, harga);
    cout << "Stok: ";
    cin >> stok;
    
     toko* barangBaru = listBarang(id, nama, kategori, harga, stok);
         if (head == nullptr) {
             head = barangBaru;
        } else {
            toko* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
            temp->next = barangBaru;
    }
}

void hapusBarang(toko*& head,int id) {
    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang dihapus.\n";
        return;
    }
    if (head->id == id) {
        toko* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Barang dengan index ID " << id << " berhasil dihapus.\n";
        return;
    }
        toko* prev = head;
    toko* curr = head->next;
        while (curr != nullptr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Barang dengan index ID " << id << " tidak ditemukan.\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Barang dengan index ID " << id << " berhasil dihapus.\n";
    }

    void editBarang(toko* head, int idEdit) {
    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang bisa diedit.\n";
        return;
    }

    toko* temp = head;
    while (temp != nullptr && temp->id != idEdit) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Barang dengan ID " << idEdit << " tidak ditemukan.\n";
        return;
    }

    cout << "Barang ditemukan. Silakan masukkan data baru:\n";
    cin.ignore();
    cout << "Nama baru     : ";
    getline(cin, temp->nama);
    cout << "Kategori baru : ";
    getline(cin, temp->kategori);
    cout << "Harga baru    : ";
    getline(cin, temp->harga);
    cout << "Stok baru     : ";
    cin >> temp->stok;

    cout << "Barang berhasil diperbarui!\n";
}

    void insertBarang(toko*& head, int setelahID) {
    int id, stok;
    string nama, kategori, harga;
    toko* current = head;
    while (current != nullptr && current->id != setelahID) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "ID " << setelahID << " tidak ditemukan. Gagal menyisipkan.\n";
        return;
    }
    cout << "Masukkan ID baru: ";
    cin >> id;
    cin.ignore();
    toko* cek = head;
    while (cek != nullptr) {
        if (cek->id == id) {
            cout << "ID sudah digunakan! Barang tidak ditambahkan.\n";
            return;
        }
        cek = cek->next;
    }

    cout << "Nama: ";
    getline(cin, nama);
    cout << "Kategori: ";
    getline(cin, kategori);
    cout << "Harga: ";
    getline(cin, harga);
    cout << "Stok: ";
    cin >> stok;

    toko* barangBaru = listBarang(id, nama, kategori, harga, stok);
    barangBaru->next = current->next;
    current->next = barangBaru;

    cout << "Barang berhasil disisipkan setelah ID " << setelahID << ".\n";
}

int main(){
    toko* head = nullptr;
    int pilihan, idHapus,idTarget;
    do{
        system("cls");
        cout << "===== Toko Komputer   =====\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Tambah Barang baru\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Edit Barang\n";
        cout << "5. Insert Barang\n";
        cout << "0. Keluar dari Inventori\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        
        switch (pilihan)
        {
          
    case 1:
        system("cls");
        cout << "Menampilkan daftar inventaris..." << endl;
        tampilkanBarang(head);
        cout << "Tekan Enter untuk melanjutkan..." << endl;
        cin.ignore();
        cin.get(); 
        break;
    case 2:
        system("cls");
        cout << "Menambahkan barang baru..." << endl;
        tambahBarang(head);
        cout << "Tekan Enter untuk melanjutkan..." << endl;
        cin.ignore();
        cin.get();
        break;
    case 3:
        system("cls");
        cout << "Masukkan ID barang yang ingin dihapus: ";
        cin >> idHapus;
        hapusBarang(head, idHapus);
        break;
    case 4:
        system("cls");
        cout << "Masukkan ID barang yang ingin diedit: ";
        cin >> idHapus; 
        editBarang(head, idHapus);
        cout << "Tekan Enter untuk melanjutkan..." << endl;
        cin.ignore();
        cin.get();
        break;
    case 5:

    system("cls");
    cout << "Masukkan ID barang setelah mana kamu ingin menyisipkan: ";
    cin >> idTarget;
    insertBarang(head, idTarget);
    cout << "Tekan Enter untuk melanjutkan..." << endl;
    cin.ignore();
    cin.get();
    break;

    case 0:
        system("cls");
        cout << "Keluar dari program..." << endl;
        break;
        default:
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        break;  
    }
    }while(pilihan != 0);
    return 0;
}