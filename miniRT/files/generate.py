def get_ambient_lighting_info():
    # Ask user for ambient lighting details
    ambient_ratio = float(input("Enter the ambient lighting ratio (0.0 to 1.0): "))
    while ambient_ratio < 0.0 or ambient_ratio > 1.0:
        print("Please enter a value between 0.0 and 1.0.")
        ambient_ratio = float(input("Enter the ambient lighting ratio (0.0 to 1.0): "))
        
    r, g, b = map(int, input("Enter the RGB values for ambient lighting (0-255, 0-255, 0-255): ").split(','))
    while not (0 <= r <= 255 and 0 <= g <= 255 and 0 <= b <= 255):
        print("Please enter RGB values between 0 and 255.")
        r, g, b = map(int, input("Enter the RGB values for ambient lighting (0-255, 0-255, 0-255): ").split(','))
    
    return f"A   {ambient_ratio}   {r},{g},{b}"

def get_camera_info():
    # Ask user for camera details
    x, y, z = map(float, input("Enter the x, y, z coordinates of the camera: ").split(','))
    orientation = input("Enter the 3D normalized orientation vector (x, y, z in range [-1, 1]): ")
    fov = float(input("Enter the horizontal field of view (0 to 180): "))
    while not (0 <= fov <= 180):
        print("Please enter a value between 0 and 180.")
        fov = float(input("Enter the horizontal field of view (0 to 180): "))
    
    return f"C   {x},{y},{z}   {orientation}   {fov}"

def get_light_info():
    # Ask user for light details
    x, y, z = map(float, input("Enter the x, y, z coordinates of the light: ").split(','))
    brightness = float(input("Enter the brightness ratio (0.0 to 1.0): "))
    while not (0.0 <= brightness <= 1.0):
        print("Please enter a value between 0.0 and 1.0.")
        brightness = float(input("Enter the brightness ratio (0.0 to 1.0): "))
    r, g, b = map(int, input("Enter the RGB values for light color (0-255, 0-255, 0-255): ").split(','))
    while not (0 <= r <= 255 and 0 <= g <= 255 and 0 <= b <= 255):
        print("Please enter RGB values between 0 and 255.")
        r, g, b = map(int, input("Enter the RGB values for light color (0-255, 0-255, 0-255): ").split(','))
    
    return f"L   {x},{y},{z}   {brightness}   {r},{g},{b}"

def get_sphere_info():
    # Ask user for sphere details
    x, y, z = map(float, input("Enter the x, y, z coordinates of the sphere center: ").split(','))
    diameter = float(input("Enter the sphere diameter: "))
    r, g, b = map(int, input("Enter the RGB values for the sphere color (0-255, 0-255, 0-255): ").split(','))
    while not (0 <= r <= 255 and 0 <= g <= 255 and 0 <= b <= 255):
        print("Please enter RGB values between 0 and 255.")
        r, g, b = map(int, input("Enter the RGB values for the sphere color (0-255, 0-255, 0-255): ").split(','))
    
    return f"sp  {x},{y},{z}   {diameter}   {r},{g},{b}"

def get_plane_info():
    # Ask user for plane details
    x, y, z = map(float, input("Enter the x, y, z coordinates of the plane point: ").split(','))
    normal_vector = input("Enter the 3D normalized normal vector (x, y, z in range [-1, 1]): ")
    r, g, b = map(int, input("Enter the RGB values for the plane color (0-255, 0-255, 0-255): ").split(','))
    while not (0 <= r <= 255 and 0 <= g <= 255 and 0 <= b <= 255):
        print("Please enter RGB values between 0 and 255.")
        r, g, b = map(int, input("Enter the RGB values for the plane color (0-255, 0-255, 0-255): ").split(','))
    
    return f"pl  {x},{y},{z}   {normal_vector}   {r},{g},{b}"

def get_cylinder_info():
    # Ask user for cylinder details
    x, y, z = map(float, input("Enter the x, y, z coordinates of the cylinder center: ").split(','))
    axis = input("Enter the 3D normalized vector of the axis (x, y, z in range [-1, 1]): ")
    diameter = float(input("Enter the cylinder diameter: "))
    height = float(input("Enter the cylinder height: "))
    r, g, b = map(int, input("Enter the RGB values for the cylinder color (0-255, 0-255, 0-255): ").split(','))
    while not (0 <= r <= 255 and 0 <= g <= 255 and 0 <= b <= 255):
        print("Please enter RGB values between 0 and 255.")
        r, g, b = map(int, input("Enter the RGB values for the cylinder color (0-255, 0-255, 0-255): ").split(','))
    
    return f"cy  {x},{y},{z}   {axis}   {diameter}   {height}   {r},{g},{b}"

def generate_rt_file():
    # Ask user to set the filename first
    file_name = input("Enter the filename for the .rt file (e.g., 'output.rt'): ").strip()
    
    with open(file_name, "w") as file:
        while True:
            obj_type = input("Enter the object type (A, C, L, sp, pl, cy) or 'exit' to quit: ").strip().lower()
            
            if obj_type == "a":
                file.write(get_ambient_lighting_info() + "\n")
            elif obj_type == "c":
                file.write(get_camera_info() + "\n")
            elif obj_type == "l":
                file.write(get_light_info() + "\n")
            elif obj_type == "sp":
                file.write(get_sphere_info() + "\n")
            elif obj_type == "pl":
                file.write(get_plane_info() + "\n")
            elif obj_type == "cy":
                file.write(get_cylinder_info() + "\n")
            elif obj_type == "exit":
                break
            else:
                print("Invalid object type. Please enter a valid type (A, C, L, sp, pl, cy).")
    
    print(f"File '{file_name}' has been created successfully.")

# Call the function to generate the .rt file
generate_rt_file()
