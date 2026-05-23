# OpenGL - Core Concepts
1. Konzepte
    * Extensions:
    Extra Features, die nicht zu Core OpenGL gehören.  
    Beispiel:  
    WGL_ARB_pixel_format  
    * State Machine:  
    OpenGL verhaltet wie ein State Machine. Beispielsweise der State beeinflusst das Ergebnis von draw Funktion.
    * Objects:  
    Ein Object ist eine Sammlung von OpenGL Optionen
    Man braucht Objects, weil eine Abstraktion für die high-level Sprachen nötig ist.

2. Frame Buffer ist ein Speicherpuffer, der Daten enthält, die alle Pixels eines Videobildes darstellen.
3. Das Bild wird im Back Buffer gezeichnet. und wenn das Bild fertig ist, Back- und Front-Buffer werden getauscht. Man sieht der Front-Buffer in Bildschirm, und Back-Buffer ist für das zeichnen genutzt. Das ist Double Buffering.
