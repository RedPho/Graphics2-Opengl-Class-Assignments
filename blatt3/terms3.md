# Aufgabe -- Element Buffer Object

EBO speichert Vertices, die mehrfach verwendet werden, nur einmal, was zu einem geringeren Speicherverbrauch und kompakteren Daten führt.

```c++
float vertices[] = {
    0.5f, 0.5f, 0.0f, // top right
    0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, // top left
};
unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3 // second triangle
};
```
# Aufgabe -- glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)

Wählt den Stil aus, wie die Vertices gerendert werden:
Linie(GL_LINE), Punkt(GL_POINT) oder Füllung(GL_FILL)
Nach der Befehl glPolygonMode(GL_FRONT_AND_BACK, GL_FILL), die Polygons, die gerendert sind, sind gefüllt mit einer Farbe.

bearbeitet von Mehmet Duman und Mehmet Emin Daşdan
