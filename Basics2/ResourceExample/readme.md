# Qt Resource Example (QRC)

## Qt Resource’a example.txt nasıl eklenir?

### Adımlar
1. Qt Creator’da projeyi aç
2. Menüden:
   **File → Add New File or Project**
3. **Qt → Qt Resource File (.qrc)** seç
4. Resource dosyasını oluştur
5. Resource Editor içinde:
   - **Add Prefix** → `new/prefix1`
   - **Add Files** → `example.txt`
6. Projeyi yeniden derle

Dosyaya kod içinden şu şekilde erişilebilir:
 ```
:/new/prefix1/example.txt
 ```
example.txt dosyası derleme sırasında executable binary dosyasının içine gömülür. 
Bu sayede uygulamayla birlikte taşınır ve programın ihtiyaç duyduğu tüm dosyalar bütünleşik olarak paketlenmiş olur.

## How to add example.txt as a Qt Resource file

### Steps
1. Open the project in Qt Creator
2. Go to:
   **File → Add New File or Project**
3. Select **Qt → Qt Resource File (.qrc)**
4. Create the resource file
5. In the Resource Editor:
   - **Add Prefix** → `new/prefix1`
   - **Add Files** → `example.txt`
6. Rebuild the project

You can access the file in code using:
```
:/new/prefix1/example.txt
```
example.txt file is embedded into the executable binary during the build process.
As a result, it is distributed together with the application, ensuring that all required files are packaged inside a single binary.
