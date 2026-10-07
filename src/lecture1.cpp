#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Book
{
    std::string title;
    int year = 0;
    std::string author;
    double price = 0.0;
};

struct Date
{
    int day = 1, month = 1, year = 2000;
};

struct Reader
{
    std::string name;
    int ticketNumber = 0;
    Date registrationDate;
    std::vector<std::string> takenBooks;
};

struct Stats
{
    int total = 0;
    int withBooks = 0;
    double averageBooks = 0.0;
};

Book inputBook()
{
    Book b;
    std::cout << "Введите название: ";
    std::getline(std::cin, b.title);
    std::cout << "Введите год издания: ";
    std::cin >> b.year;
    std::cin.ignore(); 
    std::cout << "Введите автора: ";
    std::getline(std::cin, b.author);
    std::cout << "Введите цену: ";
    std::cin >> b.price;
    if (b.price < 0)
        b.price = -b.price;
    std::cin.ignore();
    return b;
}

void printBook(const Book& b)
{
    std::cout << b.author << " — «" << b.title << "» (" << b.year << ") — " << b.price << " руб.\n";
}

void applyDiscount(Book& b, double percent)
{
    b.price = b.price - b.price * (percent / 100.0);
}

Stats calcStats(const std::vector<Reader>& readers)
{
    Stats s;
    s.total = readers.size();
    if (s.total == 0) return s;

    int totalBooks = 0;
    for (size_t i = 0; i < readers.size(); ++i)
    {
        if (readers[i].takenBooks.size() > 0)
        {
            s.withBooks++;
        }
        totalBooks = totalBooks + readers[i].takenBooks.size();
    }
    s.averageBooks = (double)totalBooks / s.total;
    return s;
}

void printReadersRegisteredBeforeYear(const std::vector<Reader>& readers, int year)
{
    for (size_t i = 0; i < readers.size(); ++i)
    {
        if (readers[i].registrationDate.year < year)
        {
            std::cout << readers[i].name << " (Билет: " << readers[i].ticketNumber << ", Дата регистрации: " 
                      << readers[i].registrationDate.day << "." << readers[i].registrationDate.month << "." << readers[i].registrationDate.year << ")\n";
        }
    }
}

bool addBookToReader(std::vector<Reader>& readers, int ticketNumber, const std::string& bookTitle)
{
    for (size_t i = 0; i < readers.size(); ++i)
    {
        if (readers[i].ticketNumber == ticketNumber)
        {
            readers[i].takenBooks.push_back(bookTitle);
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<Book> books;
    
    Book b1 = { "Война и мир", 1869, "Лев Толстой", 500.0 };
    Book b2 = { "Идиот", 1869, "Федор Достоевский", 400.0 };
    Book b3 = { "Мертвые души", 1842, "Николай Гоголь", 350.0 };
    
    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);

    std::sort(books.begin(), books.end(),
              [](const Book& a, const Book& b) { return a.year < b.year; });

    std::cout << "--- Исходные книги ---\n";
    for (size_t i = 0; i < books.size(); ++i)
    {
        printBook(books[i]);
    }

    std::cout << "\n--- Ввод пользовательских книг ---\n";
    int n;
    std::cout << "Введите количество книг (от 3 до 10): ";
    std::cin >> n;
    std::cin.ignore();

    if (n < 3) n = 3;
    if (n > 10) n = 10;

    std::vector<Book> userBooks;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "\nКнига №" << i + 1 << ":\n";
        userBooks.push_back(inputBook());
    }

    for (size_t i = 0; i < userBooks.size(); ++i)
    {
        if (userBooks[i].year < 1900)
        {
            applyDiscount(userBooks[i], 10.0);
        }
    }

    std::cout << "\n--- Результаты со скидкой для книг старше 1900 года ---\n";
    for (size_t i = 0; i < userBooks.size(); ++i)
    {
        printBook(userBooks[i]);
    }

    std::cout << "\n--- Читатели библиотеки ---\n";
    std::vector<Reader> readers;
    
    std::vector<std::string> books1;
    books1.push_back("Моби Дик");
    books1.push_back("Хоббит");
    
    std::vector<std::string> books2;
    
    std::vector<std::string> books3;
    books3.push_back("1984");
    
    std::vector<std::string> books4;
    books4.push_back("Дюна");
    books4.push_back("Основание");
    
    std::vector<std::string> books5;

    Reader r1 = { "Иванов И.И.", 101, { 15, 5, 1998 }, books1 };
    Reader r2 = { "Петров P.P.", 102, { 20, 10, 2005 }, books2 };
    Reader r3 = { "Сидоров С.С.", 103, { 1, 1, 1989 }, books3 };
    Reader r4 = { "Смирнов А.А.", 104, { 12, 12, 2015 }, books4 };
    Reader r5 = { "Кузнецов Н.Н.", 105, { 30, 8, 2022 }, books5 };

    readers.push_back(r1);
    readers.push_back(r2);
    readers.push_back(r3);
    readers.push_back(r4);
    readers.push_back(r5);

    Stats s = calcStats(readers);
    std::cout << "Статистика: Всего = " << s.total << ", С книгами на руках = " << s.withBooks 
              << ", Среднее количество книг = " << s.averageBooks << "\n";

    std::cout << "\nЧитатели, зарегистрированные ранее 2000 года:\n";
    printReadersRegisteredBeforeYear(readers, 2000);

    std::cout << "\nДобавление книги читателю с билетом 102...\n";
    addBookToReader(readers, 102, "Над пропастью во ржи");

    s = calcStats(readers);
    std::cout << "Обновленная статистика: Всего = " << s.total << ", С книгами на руках = " << s.withBooks 
              << ", Среднее количество книг = " << s.averageBooks << "\n";

    return 0;
}
