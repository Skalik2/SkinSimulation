# Problem Liszaja

Projekt "Problem Liszaja" został stworzony na potrzeby przedmiotu "programowanie w języku c++" na Politechnice Rzeszowskiej. Jego celem jest symulacja zarażania komórek skóry liszajem, co pozwala na lepsze zrozumienie procesów biologicznych zachodzących w skórze oraz badanie dynamiki rozprzestrzeniania się infekcji.

![image](https://github.com/Skalik2/SkinSimulation/assets/106670239/048e1ad0-0573-476d-9109-2945457c6dbb)


## Obsługa menu
Poruszanie po menu możliwe jest zarówno za pomocą myszki jak i klawiatury. Przy korzystaniu z klawiatury poruszanie odbywa się przez przyciski strzałek lub klawisze „WASD”.

W menu jest możliwość włączenia nowej symulacji, kontynuacji bieżącej czy też wyjście z aplikacji. W zakładce ustawienia można zaś wybrać predefiniowane rozmiary plansz jak i zmieniać kolory wyświetlanych komórek.

## Obsługa symulacji
Podczas symulacji mamy szeroką możliwość ingerencji w nią. Podstawowym narzędziem dzięki któremu otrzymamy informacje o wszystkich możliwych skrótach klawiszowych jest menu pod przyciskiem – „H”.
![liszaj](https://github.com/Skalik2/SkinSimulation/assets/106670239/0caa1277-b780-48c1-b39f-bc5b809ef85a)




Wszystkie możliwe skróty klawiszowe opisane w menu pod „H”:
- zmiana szybkości symulacji (FPS)             (↓”K”,  ↑”L”)
- zmiana szansy zarażenia                             (↓”O”,  ↑”P”)
- zmiana jednostek czasu infekcji                     (↓”V”,  ↑”B”)
- zmiana jednostek czasu odporności                     (↓”N”,  ↑”M”)
- zmiana rozmiarów planszy                      (Strzałki lub „WASD”)
- zmiana skalowania rozdzielczości  „R”
- podgląd aktualnych wartości „I”
- powrót do menu „Esc”

Za pomocą lewego przycisku myszy (LMB) możemy zarazić konkretną komórkę na planszy, co spowoduje dalszy rozwój choroby.

## Opis kodu

### Plik „SkinSimulation.cpp”
Plik ten jest głównym plikiem z którego włączamy aplikację. Zastosowana tutaj funkcja WinMain() odpowiada za wystartowanie aplikacji bez konsoli, ale za to w domyślnym oknie. W pliku inicjalizowane są właściwości okna oraz klasy odpowiedzialne za działanie całej symulacji. Ostatnim elementem w tym pliku jest nieskończona pętla rysująca całą symulację oraz wyłączanie innego wątku w przypadku gdyby było to konieczne.

### Plik „windowHelp.cpp”
Jest to plik w którym znajduje się funkcja OpenWindow(Settings& settings) przyjmująca instancję klasy settings jako referencje w argumentach. Odpowiada ona za inicjalizację nowego okna wraz z wszystkimi jego elementami takimi jak pola tekstowe czy czcionki. W pętli nieskończonej to okno jest rysowane.

### Klasa „Settings”
Klasa Settings odpowiada za przechowywanie większości zmiennych wykorzystywanych w programie.

### Klasa "Menu"
Klasa menu inicjalizuje menu programu oraz wszystkie napisy jak i przyciski czy też poruszanie się po nim.

### Klasa "EventCapture"
Klasa EventCapture jest głównie odpowiedzialna za przechwytywanie wszystkich wejść z klawiatury i myszki. Dodatkowo odpowiada za logikę zmiany scen oraz ich rysowania.

### Klasa "SkinCell"
Klasa SkinCell jest reprezentacją każdej poszczególnej komórki w symulacji. Za pomocą metod tej klasy jesteśmy w stanie modyfikować wartościami tych komórek.

### Klasa "CellArray"
Klasa CellArray jest odpowiednikiem działania na całej planszy symulacji. Dzięki niej wykonujemy takie działania jak zmiana wielkości, zarażanie kolejnych komórek, zarażanie komórki za pomocą wyboru myszką czy zmianę koloru komórek po osiągnięciu konkretnego stanu.



## License

[MIT](https://choosealicense.com/licenses/mit/)
