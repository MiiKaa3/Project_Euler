import sys
import os


def main():
  if (len(sys.argv) != 3):
    sys.exit('Too many arguments!')
    
  if (sys.argv[1] not in ['build', 'run', 'br']):
    sys.exit('sys.argv[1] must be \'build\', \'run\', or \'br\'!')
  
  num = f'{int(sys.argv[2]):03d}'
  match sys.argv[1]:
    case 'build':
      cmd = f'g++ -std=c++20 ./c++/p{num}*.cpp -o ./c++/out/p{num}'
      print(cmd)
      os.system(cmd)
      
    
    case 'run':
      cmd = f'time ./c++/out/p{num}'
      print(cmd)
      os.system(cmd)
      
    
    case 'br':
      cmd = f'g++ -std=c++20 ./c++/p{num}*.cpp -o ./c++/out/p{num} && time ./c++/out/p{num}'
      print(cmd)
      os.system(cmd)
          

if __name__ == '__main__':
  main()
