Msize = 4950

class Cell:

    def __init__(self):
        self.id = -1
        self.x = 0
        self.y = 0
        self.w = 0
        self.h = 0
        self.r = 175
        self.g = 175
        self.b = 175

    def locate(self, _x, _y, _w, _h):
        self.x = _x
        self.y = _y
        self.w = _w
        self.h = _h

    def colorize(self, id):
        self.r = randomColors[id][2]
        self.b = randomColors[id][0]
        self.g = randomColors[id][1]
        stroke(25)
        
    def fadeGray(self):
        self.r = 175
        self.b = 175
        self.g = 175
        stroke(200)

    def setStroke(self, x):
        stroke(x)

    def display(self):
        fill(self.r, self.g, self.b)
        rect(self.x, self.y, self.w, self.h)


randomColors = [[random(255), random(255), random(255)] for _ in range(200)]
grid = [Cell()for i in range(Msize)]
tabla_INode = []
lines = []
idCount = 1
idline = 0

def plot_map():
    y = 0
    for i in range(Msize):
        if(i % 90 == 0 and i > 0):
            y += 1
        #Último cuadro en la linea
        grid[i].locate((i % 90) * 12, y * 12, 12, 12)
        grid[i].setStroke(200)
        grid[i].display()
    print("PLOTED")

def drawInfo():
    stroke(0)
    fill(0)
    rect(1082, 0, 220, 650)
    fill(255)
    text("id  USER     ENL  PER    TAMANO", 1090, 20)
    
def drawNodo(lines):
    line_count = sum(1 for line in open("in.txt"))
    h = 0
    tam = 0
    stroke(0)
    fill(0)
    rect(1082, 0, 220, 650)
    fill(255)
    text("id  USER     ENL  PER    TAMANO", 1090, 20)
    for y in range(0,line_count):
        if(line_count > 0):
            h = 20 * y
        text(str(y+1)+" "+lines[y], 1090, h + 40)
        linea = lines[y]
        linea = linea.split(" ")
        tam = linea[3]
        print("Tamano " + str(y) + ": " + tam)
        drawColores(y,tam)

def drawColores(id,tam):
    y = 0
    for i in range(Msize):
        if(i%90 == 0 and i > 0):
            y += 1;
        if(i == id):
            grid[i].locate((i%90)*12,y*12,12,12)
            grid[i].setStroke(300)
            grid[i].display();
        else:
            grid[i].colorize(id-1)
    print("Colores"+str(id))
    if()

def draw():
    global lines
    global idline
    if (keyPressed and key == ENTER):
        lines = loadStrings("in.txt")
        drawNodo(lines)
        delay(300)
    elif (keyPressed and key == BACKSPACE):
        print("BACK")
        drawInfo()
        plot_map()
        delay(300)

def setup():
    size(1300, 660)
    background(0)
    drawInfo()
    plot_map()
