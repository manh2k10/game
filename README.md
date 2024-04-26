# UNO
- link preview game : 
# Cài đặt 
- Bản chạy được ngay : 
- Bản chạy trên IDE hoặc textEditor : clone repo và chạy bằng file newuno

# Nguồn
Các hình ảnh và âm thanh trong game  nguồn chủ yếu :
 https://github.com/manh2k10/UNO/tree/main/images


# Giới thiệu Game 
Uno là một trò chơi thẻ phổ biến trên toàn thế giới. Trò chơi này kết hợp yếu tố chiến thuật, may mắn và tình huống bất ngờ, 
tạo nên sự hấp dẫn và vui nhộn cho mọi đối tượng.
+ Mục tiêu của trò chơi:
  - Mục tiêu của Uno là loại bỏ tất cả các lá bài từ tay của bạn.
  - Người chơi phải đánh lá bài có cùng số hoặc màu với lá bài .
  - Nếu không thể đặt lá bài, người chơi phải rút một lá bài từ bộ bài.
  - Trong quá trình chơi, có những lá bài đặc biệt có thể làm thay đổi luật chơi và tạo ra những tình huống mới lạ.
+ Luật chơi cơ bản:
  - Mỗi người chơi được chia 7 lá bài từ bộ bài Uno.
  - Một lá bài từ bộ bài được đặt lên bàn làm nọc khởi đầu.
  - Người chơi lần lượt đặt một lá bài có màu hoặc số tương tự với lá bài trên đỉnh của nọc. Nếu không có lá bài phù hợp, họ phải rút một lá bài từ bộ bài.
  - Nếu người chơi chỉ còn một lá bài trong tay, họ phải nói "Uno" để cảnh báo các người chơi khác.
  - Trò chơi tiếp tục cho đến khi một người chơi hết bài.
+ Các lá bài đặc biệt:
  - Lá bài "Reverse" đảo chiều chơi:
       <img src="https://github.com/manh2k10/game/blob/master/images/blue10.png" width="200" alt="card" />
       
  - Lá bài "Skip" bỏ lượt chơi của người chơi tiếp theo:
       <img src="https://github.com/manh2k10/game/blob/master/images/blue11.png" width="200" alt="card" />
       
  - Lá bài "Draw Two" buộc người chơi tiếp theo phải rút hai lá bài từ bộ bài:
       <img src="https://github.com/manh2k10/game/blob/master/images/blue12.png" width="200" alt="card" />
  - Lá bài "Wild" cho phép người chơi chọn màu của nọc:
       <img src="https://github.com/manh2k10/game/blob/master/images/wild13.png" width="200" alt="card" />
  - Lá bài "Wild Draw Four" tương tự như lá bài "Wild", nhưng còn buộc người chơi tiếp theo phải rút bốn lá bài:
       <img src="https://github.com/manh2k10/game/blob/master/images/wild14.png" width="200" alt="card" />

# Bắt đầu game 
- Menu : có 2 sự lựa chọn :
  +  menu: bắt đầu vào game và chơi
         <div style="text-align: center;">
         ![menu](https://github.com/manh2k10/game/blob/master/images/menu.jpg)
     
  + Mô phỏng:
     ![menu](https://github.com/manh2k10/game/blob/master/images/phatbai.jpg)

  + EXIT : thoát game
  + WIN GAME :
   ![menu](https://github.com/manh2k10/game/blob/master/images/uno!.png)


  + THUA GAME :
   ![menu](https://github.com/manh2k10/game/blob/master/images/youlose.png)

# Source code 
- folder images : chứa hình ảnh
- folder audio : chứa âm thanh
- main.cpp : chứa hàm main để chạy chương trình
- game.cpp
  + hàm run : chứa logic game
  + hàm reset : reset dữ liệu chuẩn bị cho ván 
  + hàm terminate : giải phóng giữ liệu
  + hàm initialise :khởi tạo cửa số và dữ liệu ban đầu
- Graphics.cpp : chứa các hàm cơ bản liên quan đến sử lí đồ họa
  
- Card.cpp
  + là 1 lớp  đại diện cho 1 lá bài
- Deck.cpp
  + create():tạo 1 bộ bài và lưu trữ thông tin của các lá bài
  + shuffle() và quick_shuffle(): trộn 
  + draw(): lấy 1 lá bài từ bộ bài
  + add_card() : thêm 1 lá vào bộ bài
  + animateDeal() : hiệu ứng chuyển động của các lá bài
  
- Resource.cpp:
  + Tải các hình ảnh và âm thanh 
- def.h : định nghĩa 1 số dữ liệu
- player.cpp : quản lí người chơi
  + handadd():thêm bài
  + handremove():đánh bài
  + print():hiển thị các lá bài trên tay
  + peek():xác định lá bài muốn đánh

- Chucnang.cpp:gồm các hàm sử lí sự kiện
  + bocbai()
  + danhbai()
  + chonmau()
  + nhanbai()
- Aiplayer.cpp:gồm các hàm sử lí lượt chơi của máy
  + tương tự các hàm file chucnang.cpp

  
