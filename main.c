#include "header.h"

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	time_t start, end;
	double gap, mean, seqTimeSrt, binTimeSrt, seqCompSrt, binCompSrt, seqTimeUsrt, binTimeUsrt, seqCompUsrt, binCompUsrt;
	binaryTree BT;
	int i, komparasi;
	
	puts("================ TUGAS BESAR ISD ================");
	
	puts("1. Buatlah semua primitive Binary Tree yang diperlukan dan sesuaikan datanya dengan Buku.");
	
	puts("");
	createEmpty(&BT);
	puts("Create Empty Done...");
	puts("");
	
	puts("2. Buatlah 3 fungsi generate random masing-masing untuk (1) random Judul, (2) random Pengarang dan (3) random Pages.");
	
	puts("");
	puts("Function Ready...");
	puts("");
	
	puts("3. Inputkan 63 Buku dengan menggunakan loop ke Binary Tree. Semua 63 Buku ini Judulnya, Pengarangnya dan Pages-nya di-generate secara random, dan ID urut mulai dari 1 sd 63. Gunakan insertBST (berbasis ID Buku) untuk memasukkan Buku-buku tersebut  ke Binary Tree. Height-nya mestinya 62.");
	
	puts("");
	puts("Generating Node & Insert...");
	
	start = time(NULL);
	
	insNBook(&BT);
	
	end = time(NULL);
	gap = difftime(end, start);
	printf("\nGenerating Complete in %.2f seconds\n", gap);
	
	printf("\nHeight : %d\n", Height(BT));
	puts("Visualisasi Level Order : ");
	levelOrder(BT,0,height(BT,0));
	puts("*N adalah NULL");
	
	puts("");
	
	puts("4. Hitunglah rata-rata berapa komparasi yang terjadi dalam Search jika tiap elemen dicari.");
	
	puts("");
	puts("Loading...");
	puts("");
	
	puts("Sequential Search : ");
	seqSearchAll(&BT, &komparasi, &mean, &gap);
	printf("\nSearching Done in %.2f seconds, time mean : %.2f, total task : %d, task mean : %.2f\n", gap, mean, komparasi, mean);
	puts("");
	
	seqCompUsrt = komparasi;
	seqTimeUsrt = gap;
	
	puts("Binary Search : ");
	binSearchAll(&BT, &komparasi, &mean, &gap);
	printf("\nSearching Done in %.2f seconds, time mean : %.2f, total task : %d, task mean : %.2f\n", gap, mean, komparasi, mean);
	
	binCompUsrt = komparasi;
	binTimeUsrt = gap;
	puts("");
	
	puts("5. Balance-kan Binary Tree tersebut dengan prosedur di bawah ini atau yang diberikan terpisah. Nama prosedurnya adalah Balancing. Buktikan dengan menunjukkan Heightnya menjadi RoundDown(Log2(63))=5.");
	
	puts("");
	puts("Balance Tree...");
	
	start = time(NULL);
	
	Balancing(&BT);
	
	end = time(NULL);
	gap = difftime(end, start);
	printf("\nBalance Complete in %.2f seconds\n", gap);
	
	printf("\nHeight : %d\n", Height(BT));
	puts("Visualisasi Level Order : ");
	levelOrder(BT,0,height(BT,0));
	puts("*N adalah NULL");
	puts("");
	
	puts("6. Hitung sekali lagi rata-rata jumlah komparasi jika setiap Buku dicari/search. Caranya sama dengan No 4, hanya saja kali ini kita mempunyai pemahaman bahwa Pohon Binernya adalah balanced (seimbang), alias kanan kirinya seimbang, dan cabang kanan kirinya juga sebuah Pohon Biner Seimbang. Buat prosedur yang mampu memanggil search sekaligus menghitung banyak komparasi tiap search, menjumlahkan dan merata-ratakannya.");
	
	puts("");
	puts("Loading...");
	puts("");
	
	puts("Sequential Search : ");
	seqSearchAll(&BT, &komparasi, &mean, &gap);
	printf("\nSearching Done in %.2f seconds, time mean : %.2f, total task : %d, task mean : %.2f\n", gap, gap/NBook, komparasi, mean);
	puts("");
	
	seqCompSrt = komparasi;
	seqTimeSrt = gap;
	
	puts("Binary Search : ");
	binSearchAll(&BT, &komparasi, &mean, &gap);
	printf("\nSearching Done in %.2f seconds, time mean : %.2f, total task : %d, task mean : %.2f\n", gap, gap/NBook, komparasi, mean);
	binCompSrt = komparasi;
	binTimeSrt = gap;
	puts("");
	
	puts("7. Bandingkan hasil perhitungan rata-rata kedua metode search di atas, yaitu Sequential Search dan Binary Search.");
	
	puts("");
	puts("Answer : ");
	puts("Sequential Search : Algoritma yang kami gunakan untuk sequential search pada binary tree saat ini dibuat berdasarkan cara kerja sequential search pada array yang berfokus pada penelusuran seluruh data hingga menemukan data yang dicari. Berdasarkan percobaan search yang dilakukan di atas didapat data bahwa :");
	puts("Pada saat tree belum balance : ");
	printf("Total Komparasi : %.2f\n", seqCompUsrt);
	printf("Rata - Rata Komparasi : %.2f\n", seqCompUsrt/NBook);
	printf("Total Waktu : %.2f\n", seqTimeUsrt);
	printf("Rata - Rata Waktu : %.2f\n", seqTimeUsrt/NBook);
	puts("Pada saat tree sudah balance : ");
	printf("Total Komparasi : %.2f\n", seqCompSrt);
	printf("Rata - Rata Komparasi : %.2f\n", seqCompSrt/NBook);
	printf("Total Waktu : %.2f\n", seqTimeSrt);
	printf("Rata - Rata Waktu : %.2f\n", seqTimeSrt/NBook);
	
	puts("Binary Search : Algoritma yang kami gunakan untuk binary search pada binary tree saat ini dibuat berdasarkan cara kerja binary search pada array yang arah penelusurannya ditentukan dari nilai data yang 'urut' dengan standar tertentu agar tidak perlu melakukan penelusuran secara menyeluruh dan akan berhenti ketika menemukan data yang dicari. Berdasarkan percobaan yang dilakukan di atas didapat data bahwa : ");
	puts("Pada saat tree belum balance : ");
	printf("Total Komparasi : %.2f\n", binCompUsrt);
	printf("Rata - Rata Komparasi : %.2f\n", binCompUsrt/NBook);
	printf("Total Waktu : %.2f\n", binTimeUsrt);
	printf("Rata - Rata Waktu : %.2f\n", binTimeUsrt/NBook);
	puts("Pada saat tree sudah balance : ");
	printf("Total Komparasi : %.2f\n", binCompSrt);
	printf("Rata - Rata Komparasi : %.2f\n", binCompSrt/NBook);
	printf("Total Waktu : %.2f\n", binTimeSrt);
	printf("Rata - Rata Waktu : %.2f\n", binTimeSrt/NBook);
	puts("");
	
	/*
	Answer :
	Sequential Search : Algoritma yang kami gunakan untuk sequential search pada binary tree saat ini dibuat berdasarkan cara kerja sequential search pada array yang berfokus pada penelusuran seluruh data hingga menemukan data yang dicari. Berdasarkan percobaan search yang dilakukan di atas didapat data bahwa :
	Pada saat tree belum balance :
	Total Komparasi : 961.00
	Rata - Rata Komparasi : 31.00
	Total Waktu : 0.00
	Rata - Rata Waktu : 0.00
	Pada saat tree sudah balance :
	Total Komparasi : 227.00
	Rata - Rata Komparasi : 7.32
	Total Waktu : 0.00
	Rata - Rata Waktu : 0.00
	Binary Search : Algoritma yang kami gunakan untuk binary search pada binary tree saat ini dibuat berdasarkan cara kerja binary search pada array yang arah penelusurannya ditentukan dari nilai data yang 'urut' dengan standar tertentu agar tidak perlu melakukan penelusuran secara menyeluruh dan akan berhenti ketika menemukan data yang dicari. Berdasarkan percobaan yang dilakukan di atas didapat data bahwa :
	Pada saat tree belum balance :
	Total Komparasi : 496.00
	Rata - Rata Komparasi : 16.00
	Total Waktu : 0.00
	Rata - Rata Waktu : 0.00
	Pada saat tree sudah balance :
	Total Komparasi : 129.00
	Rata - Rata Komparasi : 4.16
	Total Waktu : 0.00
	Rata - Rata Waktu : 0.00
	*/
	
	puts("8. Simpulkan bagus mana antara Sequential Search dan Binary Search jika mula-mula data tidak urut? SequentialSearch tidak memerlukan data dalam keadaan sorted (urut), sedangkan BinarySearch butuh data yang sorted (urut). Maka BinarySearch haruslah menghitung juga biaya Sortingnya. Bagus mana? Jelaskan jawaban anda dan mengapa?");
	puts("");
	puts("Answer : Berdasarkan data dari percobaan diatas jika data tidak urut sama sekali maka sequential search jauh lebih baik dibandingkan binary search untuk mencari suatu data karena pencarian dilakukan secara menyeluruh sehingga tidak bergantung pada urutan nilai data meskipun kurang efisien.");
	puts("Jika binary tree memiliki standar BST baik sudah maupun belum balance maka binary tree jauh lebih unggul karena memiliki jumlah komparasi yang lebih sedikit yang berarti jauh lebih efisien.");
	puts("Hal ini disebabkan karena data yang sudah 'urut' dengan standar BST memiliki pola tetap pada besar kecilnya nilai data, binary search memanfaatkan nilai data untuk membatasi area pencarian sehingga jauh lebih efisien meskipun sangat bergantung pada nilai data. Sedangkan pada sequential search tidak terlalu bergantung pada besar atau kecilnya nilai data maupun urutannya karena melakukan pencarian ke seluruh area dan efeknya memiliki efisiensi yang buruk");
	puts("");
	
	puts("Show All Data (Pre Order) :");
	preOrder(BT, true);
	
	puts("End...");
	
	/*
	Answer : Berdasarkan data dari percobaan diatas jika data tidak urut sama sekali maka sequential search jauh lebih baik dibandingkan binary search untuk mencari suatu data karena pencarian dilakukan secara menyeluruh sehingga tidak bergantung pada urutan nilai data meskipun kurang efisien. 
	Jika binary tree memiliki standar BST baik sudah maupun belum balance maka binary tree jauh lebih unggul karena memiliki jumlah komparasi yang lebih sedikit yang berarti jauh lebih efisien. 
	Hal ini disebabkan karena data yang sudah 'urut' dengan standar BST memiliki pola tetap pada besar kecilnya nilai data, binary search memanfaatkan nilai data untuk membatasi area pencarian sehingga jauh lebih efisien meskipun sangat bergantung pada nilai data. 
	Sedangkan pada sequential search tidak terlalu bergantung pada besar atau kecilnya nilai data maupun urutannya karena melakukan pencarian ke seluruh area dan efeknya memiliki efisiensi yang buruk
	*/
	
	return 0;
}
