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

int main(){

}