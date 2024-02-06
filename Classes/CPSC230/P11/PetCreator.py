#Richard Graedon Beeler
#2423448
#beeler@chapman.edu
#Assignment 11

class Pet:

    def __init__(self,name,owner_name,age,breed):
        self.name = name
        self.owner = owner_name
        self.age = age
        self.breed = breed
       

    def print_pet(self):
        str_name = "Name: " + self.name
        print(f"{str_name: ^50}")
        str_owner = "Owner: " + self.owner
        print(f"{str_owner: ^50}")
        str_breed = "Breed: " + self.breed
        print(f"{str_breed: ^50}")
        str_age = "Age: " + str(self.age)
        print(f"{str_age: ^50}")
        print()

def input_parameters():
    pet_name = input("Enter name of pet: ")
    pet_owner = input("Enter name of owner: ")
    while True:
        try:
            pet_age = int(input("Enter pet's age: "))
            break
        except:
         print("Invalid age, please enter an integer.")
    pet_breed = input("Enter pet's breed: ")
    print()
    return pet_name, pet_owner,pet_age,pet_breed

name_pet,owner_pet,age_pet,breed_pet = input_parameters()
p1 = Pet(name_pet,owner_pet,age_pet,breed_pet)
#p1.print_pet()

name_pet,owner_pet,age_pet,breed_pet = input_parameters()
p2 = Pet(name_pet,owner_pet,age_pet,breed_pet)
#p2.print_pet()

name_pet,owner_pet,age_pet,breed_pet = input_parameters()
p3 = Pet(name_pet,owner_pet,age_pet,breed_pet)
#p3.print_pet()

print('\033[1m' + 'Pet 1:' + '\033[0m')
p1.print_pet()
print('\033[1m' + 'Pet 2:' + '\033[0m')
p2.print_pet()
print('\033[1m' + 'Pet 3:' + '\033[0m')
p3.print_pet()