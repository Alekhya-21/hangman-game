import random
print("Welcome to Hangman!")
words=["apple","banana","mango","orange"]
secret_word=random.choice(words)
tries=6
guessed_letters=[]
while(tries>0):
  display=""
  for i in secret_word:
    if i in guessed_letters:
      display+=i
    else:
      display+=" _"
  print("word :",display)
  # check win
  if "_" not in display:
    print("You guessed the word!!")
    break
  letter=input("Guess a letter :")

  # check if the letter is already existed
  if letter in guessed_letters:
    print("letter is already guessed.")
  guessed_letters.append(letter)

  #check if the guessed the wrong letter
  if letter not in secret_word:
    tries-=1
    print(f"wrong guess, tries left {tries}")
else:
  print("You lost, the word was :",secret_word)