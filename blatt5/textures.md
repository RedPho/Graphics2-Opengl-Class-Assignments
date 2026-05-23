# Texturen Begriffe

## Begriffe
- 
### Textur
Texturen sind Container für Daten. Mit Texturen können große Mengen an Daten zum Shader gesendet werden.  
- 
### Texel
Texel ist ein Pixel in einer Textur.  
- 
### Texturkoordinate
Die Texturkoordinate gibt an, von welchem Teil des Texturbildes eine Probe genommen werden soll.  
- 
### Texture Wrapping
„Wrapping“ geschieht, wenn wir Texturkoordinaten außerhalb von (0,0) bis (1,1) angeben. Das Standardverhalten von OpenGL ist es, die Texturbilder zu wiederholen.  
- 
### Texture Filtering
Texturkoordinaten hängen nicht von der Auflösung ab, sondern können jeder beliebige Fließkommawert sein, so dass OpenGL herausfinden muss, welchem Texturpixel (auch bekannt als a ) die Texturkoordinate zugeordnet werden soll. Diese Entscheidung heißt Texture Filtering.
- 
### Texture Unit
Location of a texture (Uniform)

## Mipmaps
- Mipmaps sind eine Sammlung von Texturbildern, bei denen jede nachfolgende Textur doppelt so klein ist wie die vorherige. Ab einer bestimmten Entfernung vom Betrachter verwendet OpenGL eine andere Mipmap-Textur, die am besten zum Objekt passt. Da das Objekt weit entfernt ist, wird die geringere Auflösung für den Benutzer nicht spürbar sein. OpenGL ist dann in der Lage, die richtigen Texel abzutasten, und es ist weniger Cache-Speicher erforderlich, wenn dieser Teil der Mipmaps abgetastet wird.
- 33% mehr. Das wird erreicht, indem die
Farbkanäle der Textur auf eine bestimmte Art angeordnet werden.

## Filtering
- Bild A: Linear Filtering  
- Bild B: Nearest Neighbour Filtering  

## Wrapping
- Bild A: GL_CLAMP_TO_BORDER
- Bild B: GL_MIRRORED_REPEAT
- Bild C: GL_CLAMP_TO_EDGE
- Bild D: GL_REPEAT
