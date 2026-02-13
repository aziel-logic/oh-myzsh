#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Post
{
  string isi;
  vector<Post *> balasan;
};

// Membuat Data
// Cari Cabang
// Tambah Root
// Tambah Cabang
// Tampilkan Tree
// Tampilkan

// Membuat Data
Post *buatPost(string isi)
{
  Post *p = new Post();
  p->isi = isi;
  return p;
}

// Cari Cabang
Post *cariPost(Post *root, const string &isi)
{
  if (root->isi == isi)
    return root;

  for (int i = 0; i < root->balasan.size(); i++)
  {
    Post *hasil = cariPost(root->balasan[i], isi);
    if (hasil != NULL)
      return hasil;
  }
  return NULL;
}

// Tambah Root
void tambahTopik(vector<Post *> &forum)
{
  cin.ignore();
  string isi;
  cout << "Masukkan judul topik diskusi: ";
  getline(cin, isi);

  forum.push_back(buatPost(isi));
  cout << "Topik berhasil dibuat!\n";
}

// Tambah Cabang
void tambahBalasan(vector<Post *> &forum)
{
  cin.ignore();
  string target, isi;

  cout << "Balas posting yang berisi: ";
  getline(cin, target);
  Post *parent = NULL;
  for (int i = 0; i < forum.size(); i++)
  {
    parent = cariPost(forum[i], target);
    if (parent != NULL)
      break;
  }
  if (parent == NULL)
  {
    cout << "Posting tidak ditemukan!\n";
    return;
  }
  cout << "Tulis balasan: ";
  getline(cin, isi);
  parent->balasan.push_back(buatPost(isi));
  cout << "Balasan berhasil ditambahkan!\n";
}

// Tampilkan Tree
void tampilkanThread(Post *root, int level)
{
  for (int i = 0; i < level; i++)
    cout << "  ";
  cout << "- " << root->isi << endl;

  for (int i = 0; i < root->balasan.size(); i++)
  {
    tampilkanThread(root->balasan[i], level + 1);
  }
}

// Tampilkan Aplikasi
void tampilkanForum(vector<Post *> &forum)
{
  cout << "\n=== FORUM DISKUSI ===\n";
  for (int i = 0; i < forum.size(); i++)
  {
    tampilkanThread(forum[i], 0);
  }
}

int main()
{
  vector<Post *> forum; // banyak topik diskusi

  int pilih;
  do
  {
    cout << "\n=== APLIKASI FORUM DISKUSI E-LEARNING ===\n";
    cout << "1. Buat topik diskusi\n";
    cout << "2. Tambah komentar/balasan\n";
    cout << "3. Tampilkan seluruh forum\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      tambahTopik(forum);
      break;
    case 2:
      tambahBalasan(forum);
      break;
    case 3:
      tampilkanForum(forum);
      break;
    case 0:
      cout << "Keluar...\n";
      break;
    default:
      cout << "Pilihan tidak valid!\n";
    }

  } while (pilih != 0);

  return 0;
}
