from PIL import Image, ImageDraw

def apply_border_radius(image_path, output_path, radius):
    # Open the image
    img = Image.open(image_path).convert("RGBA")
    width, height = img.size
    
    # Create a mask with rounded corners
    mask = Image.new("L", (width, height), 0)
    draw = ImageDraw.Draw(mask)
    draw.rounded_rectangle((0, 0, width, height), radius=radius, fill=255)

    # Apply the mask to the image
    rounded_img = Image.new("RGBA", img.size)
    rounded_img.putalpha(mask)
    rounded_img.paste(img, (0, 0), mask)
    
    # Save the result
    rounded_img.save(output_path, format="PNG")

# Example usage
apply_border_radius("favicon.jpg", "favicon.ico", radius=150)
