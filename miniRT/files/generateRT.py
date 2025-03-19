import random

def get_random_ambient_lighting():
    # Randomize the ambient lighting ratio and RGB values
    ambient_ratio = round(random.uniform(0.0, 1.0), 2)
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    
    return f"A   {ambient_ratio}   {r},{g},{b}"

def get_random_camera():
    # Randomize camera coordinates and FOV
    x = random.uniform(-100.0, 100.0)
    y = random.uniform(-100.0, 100.0)
    z = random.uniform(0.0, 100.0)
    orientation = f"{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f}"
    fov = random.randint(0, 180)
    
    return f"C   {x:.2f},{y:.2f},{z:.2f}   {orientation}   {fov}"

def get_random_light():
    # Randomize light coordinates, brightness, and color
    x = random.uniform(-100.0, 100.0)
    y = random.uniform(-100.0, 100.0)
    z = random.uniform(0.0, 100.0)
    brightness = round(random.uniform(0.0, 1.0), 2)
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    
    return f"L   {x:.2f},{y:.2f},{z:.2f}   {brightness}   {r},{g},{b}"

def get_random_sphere():
    # Randomize sphere coordinates, diameter, and color
    x = random.uniform(-100.0, 100.0)
    y = random.uniform(-100.0, 100.0)
    z = random.uniform(0.0, 100.0)
    diameter = random.uniform(1.0, 20.0)
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    
    return f"sp  {x:.2f},{y:.2f},{z:.2f}   {diameter:.2f}   {r},{g},{b}"

def get_random_plane():
    # Randomize plane coordinates, normal vector, and color
    x = random.uniform(-100.0, 100.0)
    y = random.uniform(-100.0, 100.0)
    z = random.uniform(-100.0, 0.0)
    normal_vector = f"{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f}"
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    
    return f"pl  {x:.2f},{y:.2f},{z:.2f}   {normal_vector}   {r},{g},{b}"

def get_random_cylinder():
    # Randomize cylinder coordinates, axis, diameter, height, and color
    x = random.uniform(-100.0, 100.0)
    y = random.uniform(-100.0, 100.0)
    z = random.uniform(0.0, 100.0)
    axis = f"{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f},{random.uniform(-1.0, 1.0):.2f}"
    diameter = random.uniform(1.0, 20.0)
    height = random.uniform(1.0, 50.0)
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    
    return f"cy  {x:.2f},{y:.2f},{z:.2f}   {axis}   {diameter:.2f}   {height:.2f}   {r},{g},{b}"

def generate_rt_file():
    # Ask user to set the filename first
    file_name = input("Enter the filename for the .rt file (e.g., 'output.rt'): ").strip()
    
    # Open the file for writing
    with open(file_name, "w") as file:
        while True:
            obj_type = input("Enter the object type (A, C, L, sp, pl, cy) or 'exit' to quit: ").strip().lower()
            
            if obj_type == "a":
                file.write(get_random_ambient_lighting() + "\n")
            elif obj_type == "c":
                file.write(get_random_camera() + "\n")
            elif obj_type == "l":
                file.write(get_random_light() + "\n")
            elif obj_type == "sp":
                file.write(get_random_sphere() + "\n")
            elif obj_type == "pl":
                file.write(get_random_plane() + "\n")
            elif obj_type == "cy":
                file.write(get_random_cylinder() + "\n")
            elif obj_type == "exit":
                break
            else:
                print("Invalid object type. Please enter a valid type (A, C, L, sp, pl, cy).")
    
    print(f"File '{file_name}' has been created successfully.")

# Call the function to generate the .rt file
generate_rt_file()
