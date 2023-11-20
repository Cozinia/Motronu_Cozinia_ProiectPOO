# Sistem de Gestionare a Muzicii
### Descriere Generală
Acest proiect implementează un sistem de gestionare a muzicii. Include clase pentru gestionarea artiștilor, albumelor și melodiilor. Sistemul permite utilizatorilor să creeze, să modifice și să afișeze informații despre artiști, albume și melodii.

## Clase
### 1. Artist
- Gestionază informații despre artiști, inclusiv nume, vârstă, avere, genuri și altele.
- Suportă constructori pentru valori implicite, complete și cu doi parametri, precum și un constructor de copiere.
- Include metode de preluare și setare pentru a accesa și modifica informațiile despre artist.
- Suprascrie operatorii pentru afișare, comparație și intrare.
### 2. Album
- Gestionază informații despre albume, inclusiv nume, anul lansării, preț și lista de melodii.
- Suportă constructori pentru valori implicite, cu doi parametri, complete, precum și un constructor de copiere.
- Include metode de preluare și setare pentru a accesa și modifica informațiile despre album.
- Implementează o funcție prieten pentru afișarea informațiilor despre album și melodii.
### 3. Melodie
- Gestionază informații despre melodii, inclusiv nume, numele artistului, durată și versuri.
- Suportă constructori pentru valori implicite, cu doi parametri, complete, precum și un constructor de copiere.
- Include metode de preluare și setare pentru a accesa și modifica informațiile despre melodie.
- Implementează o funcție prieten pentru afișarea informațiilor despre melodie și asocierea cu artistul.
### Funcționalități
- Codul sursă include, de asemenea, mai multe funcții prietene pentru afișarea informațiilor și suprascrieri de operatori pentru comparație și afișare a obiectelor.

- `afisareMelodieArist`: Afișează informații despre asocierea dintre un artist și o melodie.

- `afisareAlbumMelodii`: Afișează informații despre asocierea dintre un album și o melodie.

- Suprascrieri pentru operatorii de flux (`<<` și `>>`) pentru afișare și intrare.

- Suprascrieri pentru operatorii de comparație (`>`, `!=`) pentru artiști, melodii și albume.

### Utilizare
- Funcția principală demonstrează utilizarea claselor implementate. Creează instanțe ale artiștilor, albumelor și melodiilor și evidențiază funcționalitățile metodelor de preluare și setare, operatorilor de comparație și suprascrierilor pentru intrare/ieșire.

- Utilizatorii pot introduce informații despre artiști, albume și melodii în timpul rulării. Programul afișează apoi informațiile introduse și efectuează comparații între diferite obiecte.

### Concluzie
Acest sistem de gestionare a muzicii oferă o bază pentru gestionarea informațiilor despre artiști, albume și melodii într-un mod simplu și intuitiv. Utilizatorii pot extinde și modifica codul pentru a se potrivi cerințelor specifice ale unei aplicații de gestionare a muzicii.