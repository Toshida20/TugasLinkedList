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

int main(){

}