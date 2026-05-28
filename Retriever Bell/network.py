"""
File:    network.py
Author:  Tahmid Khan
Date:    05/04/25
Section: 16
E-mail:  tahmidk1@umbc.edu
Description:
A call center, that takes area codes, and then phone number associated with the area code, and connects them.
"""
#Preset variables for the program, made them because it was less typing and easier to change
cmd_prompt = "Enter a command: "
quit_cmd = "quit"
save_cmd = "network-save"
load_cmd = "network-load"
display_cmd = "display"
switch_add = "switch-add"
switch_connect = "switch-connect"
phone_add = "phone-add"
startcall = "start-call"
endcall = "end-call"
na_use = "not in use"
na_connected = "not connected"
not_found = "not found"

#Function that creates a network, and makes it a dictionary
def create_network():
  return {}

#Function that creates a switch, and makes the trunks a list and the phones a dictionary
def create_switch():
  return {"trunks": [], "phones": {}}

#Function that creates a phone and makes the connected_to and in_use variables
def create_phone():
  return {"connected_to": na_connected, "in_use": na_use}

#Function that adds a switch to the network by checking if the area code is in the network, if it is it returns, if not it adds the switch
def add_switch(network, area_code):
  if area_code in network:
    return
  network[area_code] = create_switch()  

#Function that connects switches by checking if the area codes are in the network, if they are it adds the area code to the trunks
def connect_switches(network, area_code1, area_code2):
  if area_code1 in network and area_code2 in network:
    if area_code2 not in network[area_code1]["trunks"]:
      network[area_code1]["trunks"].append(area_code2)
    if area_code1 not in network[area_code2]["trunks"]:
      network[area_code2]["trunks"].append(area_code1)

#Function that adds a phone to the network by checking if the area code is in the network, if it is it adds the phone to the phones dictionary
def add_phone(network, full_number):
  parts = full_number.split("-")
  area_code = parts[0]
  number = ''.join(parts[1:])
  if area_code not in network:
    return
  phones = network[area_code]["phones"]
  if number in phones:
    return
  phones[number] = create_phone()  

#Function that gets the phone by checking if the area code is in the network, if it is it checks if the number is in the phones dictionary, if it is it returns the phone, area code, and number
def get_phone(network, full_number):
  parts = full_number.split("-")
  area_code = parts[0]
  number = ''.join(parts[1:])
  if area_code in network:
    phones = network[area_code]["phones"]
    if number in phones:
      return phones[number], area_code, number
  return not_found, area_code, number    

#Function that checks if the network can connect by checking if the current area code is the target area code, if it is it returns true, otherwise it checks the trunks and calls itself recursively
def can_connect(network, current, target, visited):
  visited.append(current)
  if current == target:
    return True
  trunks = network[current]["trunks"]
  index = 0
  while index < len(trunks):
    next_area = trunks[index]
    found = False
    i = 0
    while i < len(visited):
      if visited[i] == next_area:
        found = True
      i += 1
    if not found:
      result = can_connect(network, next_area, target, visited)
      if result:
        return True
    index += 1
  return False  

#Function that starts a call by checking if the phones are in the network, if they are it checks if they are connected, if they are it checks if the network can connect, if it can it connects the phones
def start_call(network, full_number1, full_number2):
  phone1, code1, full_number1 = get_phone(network, full_number1)
  phone2, code2, full_number2 = get_phone(network, full_number2)
  if phone1 == not_found or phone2 == not_found:
    print("One of the number does not exist type: areacode-number example: 443-1234567")
    return
  if phone1["connected_to"] != na_connected or phone2["connected_to"] != na_connected:
    print("One of the phones is already in use")
    return
  path_exists = can_connect(network, code1, code2, [])
  if path_exists:
    phone1["connected_to"] = full_number2
    phone2["connected_to"] = full_number1
    print(f"{full_number1} is connected to {full_number2}")
  else:
    print(f"{full_number1} and {full_number2} were not connected")

#Function that ends a call by checking if the phone is in the network, if it is it checks if it is connected, if it is it disconnects the phones
def end_call(network, full_number):
  phone1, code1, full_number1 = get_phone(network, full_number)
  if phone1 == not_found:
    print("Phone number does not exist type: areacode-number example: 443-1234567")
    return
  other = phone1["connected_to"]
  if other == na_connected:
    print(f"{full_number} is not currently in a call")
    return
  phone2, code2, full_number2 = get_phone(network, other)
  phone1["connected_to"] = na_connected
  if phone2!= not_found:
    phone2["connected_to"] = na_connected
  print(f"{full_number} has ended the call")

#Function that displays the network by printing the area code, the trunks, and the phones
def display_network(network):
  for code in network:
    print(f"switchboard with area code {code}")
    print("trunk lines are:")
    trunks = network[code]["trunks"]
    t_index = 0
    while t_index < len(trunks):
      print(f"      trunk line connection to: {trunks[t_index]}")
      t_index +=1
    print("local phones connected are:")  
    phones = network[code]["phones"]
    for number in phones:
      phone = phones[number]
      if phone["connected_to"] != na_connected:
        print(f"phone {number} is connected to {phone['connected_to']}")
      else:
        print(f"phone {number} is {na_use}")

#Function that saves the network to a file by writing the area code, the trunks, and the phones to the file
def save_network(network, filename):
  f = open(filename, "w")
  for code in network:
    f.write(f"SWITCH: {code}\n")
    for trunk in network[code]["trunks"]:
      f.write(f"TRUNK: {trunk}\n")
    for phone in network[code]["phones"]:
      f.write(f"PHONE: {phone}\n")
      target = network[code]["phones"][phone]["connected_to"]
      if target != na_connected:
        f.write(f"CONNECTED:{phone}, {target}\n")
  f.close()
  print(f"Network saved to {filename}")

#Function that loads the network from a file by reading the file and adding the area code, the trunks, and the phones to the network
def load_network(filename):
  f = open(filename, "r")
  lines = f.readlines()
  f.close()
  net = create_network()
  current_ac = ""
  for line in lines:
    line = line.strip()
    if len(line) >= 7 and line[:7] == "SWITCH:":
      current_ac = line[7:].strip()
      add_switch(net, current_ac)
    elif len(line) >=8 and line[:8] == "  TRUNK:":
      connect_switches(net, current_ac, line[8:])
    elif len(line) >=7 and line[:7] == "  PHONE:":
      add_phone(net, current_ac + "-" + line[7:])
    elif len(line) >= 10 and line[:10] == "    CONNECTED:":
      parts = line[10:].split(",")
      a = parts[0].strip()
      b = parts[1].strip()
      net[current_ac]["phones"][a]["connected_to"] = b
  print(f"Network loaded from {filename}")
  return net

#Main function that runs the program by checking the command and calling the appropriate function
def main():
  network = create_network()
  active = True
  while active:
    cmd = input(cmd_prompt).strip()
    if cmd != "":
      parts = cmd.split()
      cmd = parts[0]
      if cmd == quit_cmd:
        active = False
      elif cmd == switch_add and len(parts) == 2:
        add_switch(network, parts[1])
      elif cmd == switch_connect and len(parts) == 3:
        connect_switches(network, parts[1], parts[2])
      elif cmd == phone_add and len(parts) == 2:
        add_phone(network, parts[1])
      elif cmd == startcall and len(parts) == 3:
        start_call(network, parts[1], parts[2])
      elif cmd == end_call and len(parts) == 2:
        end_call(network, parts[1])
      elif cmd == display_cmd:
        display_network(network)
      elif cmd == save_cmd and len(parts) == 2:
        save_network(network, parts[1])
      elif cmd == load_cmd and len(parts) == 2:
        network = load_network(parts[1])
      else:
        print("Invalid command")

if __name__ == "__main__":
  main()
    
