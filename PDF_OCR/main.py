import pytesseract
from pdf2image import convert_from_path


path = "doc.pdf"
images = convert_from_path(path)

text_output = ""
for i, img in enumerate(images):
    text = pytesseract.image_to_string(img)
    text_output += f"\n--- Page {i + 1} --- \n{text}"

with open("extracted_text.txt", "w", encoding="utf-8") as file:
    file.write(text_output)

print("OCR complete. Text saved to 'extracted_text.txt'.")
