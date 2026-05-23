# OpenGL Pipeline

1. Vertex Data[] (Eingabe): eine Sammlung von Vertices.
2. Vertex Shader: Es Transformiert 3D-Koordinaten in andere 3D-Koordinaten
3. Geometry Shader: Es nimmt als Eingabe eine Sammlung von Scheitelpunkten, die ein Primitiv bilden, und erzeugt andere Formen, indem er neue Scheitelpunkte hinzufügt, um neue Primitive zu bilden.
4. Shape Assembly (Primitive Assembly): Es nimmt die Vertices, die ausgabe von Vertex oder Geometry Shader sind, und bildet Primitive.
5. Rasterization: Es mappt die Primitive aus den vorherigen Schritt auf die Screen Pixels.
6. Fragment Shader: Es berechnet den finalen Pixelfarbe. Es benutzt die daten von 3D Scenes wie lighting.
7. Tests and Blending: Es prüft die entsprechende Tiefe des Fragments und verwendet diese, um zu prüfen, ob das resultierende Fragment vor oder hinter anderen Objekten liegt. Es prüft auch die Alphawerte und mischt die Objekte entsprechend.
