# Phân tích tổng luỹ thừa (đệ quy)
Giải thích thuật toán:
  - Bây giờ ta muốn phân tích 1 số X thành các luỹ thừa bậc n ta thực hiện như sau:
    + Ta sẽ xuất phát từ số 0, giả sử X = 0^n + A (tức là xét từ số 0 xem X có thể phân tích được thành dãy như đề bài yêu cầu mà trong đó có 1 số hạng là       số 0^n hay không)
          + Khi này A phải có dạng A = 1^n + B (tức là không thể có 0^n vì các số hạng khác nhau) hay X - 0^n = 1^n + B
          + Khi đó B lại phải có dạng B = 2^n + C hay X - 0^n - 1^n = 2^n + C
          + Cứ tiếp như vậy cho đến khi vế trái ( X - ... -...) <= 0, nếu vế trái bằng 0 thì số 0 ta xét là thoả mãn (biến đếm +1), nếu nhỏ hơn 0 thì không             làm gì cả mà xét sang số 1
    + Tiếp theo là đến số 1, ta lặp lại các bước như vừa rồi xem có cách nào để phân tích số X thành tổng các luỹ thừa mà trong đó có 1 số hạng là 1^n hay       không
    + ...... tiếp tục xét như vậy đến số X (tức là xét sự xuất hiện của số hạng X^n)
-------------------
*NOTE: Các dãy được xét rồi sẽ không bị xuất hiện lại do tính chất xét tăng dần, vd 13 = 2^2 + 3^2 thì nếu xét qua số 2 ta sẽ có 1 trường hợp nhưng xét     đến số 3 sẽ không có trường hợp nào cả vì sẽ không xét ngược lại 2
-------------------
  ---> Tất cả các thao tác trên, ta có thể viết dưới dạng công thức (theo kiểu vòng lặp):
    Ta tạo ra 1 biến toàn cục chịu trách nhiệm lưu trữ giá trị đếm hiện tại (nếu dùng biến cục bộ thì sẽ bị khai báo lại và mất dữ liệu) và 1 hàm dem(X,n, k) với X là số cần đếm cách phân tích thành tổng luỹ thừa bậc n, n là bậc n, k là số xuất phát để phân tích, hàm dem sẽ có cú pháp:
    
    dem(int X, int n, int k) {
      if (X == 0) d++;
      if (X>0) {
        for (i = k+1; i <= X; i++){
          dem(X - pow(i,n) , n , i);
          // VD lượt đầu: gọi lại hàm dem với giá trị X mới là A (A được định nghĩa như bên trên), giá trị xuất phát mới là 1 (i=1)//
        } 
      }
    }
    
   ----> Khi này ở hàm main ta sẽ gọi hàm dem(X,n,0) vì cho biến i ban đầu chạy = 0.
   
_____________
Cám ơn các bạn đã đọc đến đây! Chúc các bạn học tốt !
