from PIL import Image as img

image = img.open("image.jpg")
width, height = image.size

with open("output.txt", "w") as file:
    
    for y in range(height): #across all rows
        for x in range(width): #across all columns
            r, g, b = image.getpixel((x, y))
            brightness = (0.299 * r) + (0.587 * g) + (0.114 * b)
            brightness = int((brightness / 255) * 1000)
            if(brightness < 100):
                file.write('..')
            elif(100 <= brightness < 200):
                file.write(',,')
            elif(200 <= brightness < 300):
                file.write('--')
            elif(300 <= brightness < 400):
                file.write('<<')
            elif(400 <= brightness < 500):
                file.write('++')
            elif(500 <= brightness < 600):
                file.write('^^')
            elif(600 <= brightness < 700):
                file.write('!!')
            elif(700 <= brightness < 800):
                file.write('$$')
            elif(800 <= brightness < 900):
                file.write('##')
            elif(900 <= brightness <= 1000):
                file.write('@@')
        file.write("\n")
        
