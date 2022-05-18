name = input('What is your name? ')
print('Welcome ' + name + ', this expert system will help you distinguish between diseases with similar symptomps like Flu, Common Cold, Covid-19 and Pneumonia depending on severity of symptomps you are showing.')
flu=0
cold=0
c19=0
pneumonia=0
questions=["What is patient's age?",
           "What is patient's body temparature?",
           'What is the oxygen level?']
           
yesnoqs=['Are you experiencing cough and sore throat?',
         'Do you have a runny nose?',
         'Are you experiencing sneezing?',
         'Do you have a headache?',
         'Do you have body/muscular aches?',
         'Are you experiencing regular tiredness?',
         'Do you have a fever?',
         'Have you experienced any vomiting or diarrhea?',
         'Have you felt any shortness of breath and chest pain?',
         'Have you lost your sense of smell or taste?']
age, body_temp, oxy_level = (0, 0, 0)
print('Answer the following questions.')
qno = 1
for q in questions:
    print(q)
    if(qno == 1):
        age = int(input())
    elif(qno == 2):
        body_temp = float(input())
    elif(qno == 3):
        oxy_level = float(input())
    qno+=1

print('Answer the following questions with Y/N.')
for i in range(len(yesnoqs)):
    print(yesnoqs[i])
    ans = input()
    if(i == 0 and (ans == 'Y' or ans == 'y')):
        flu+=1
        cold+=1
        c19+=1
        pneumonia+=1
    elif(i == 1 and (ans == 'Y' or ans == 'y')):
        flu+=1
        cold+=1
    elif(i == 2 and (ans == 'Y' or ans == 'y')):
        cold+=1
        c19+=1
    elif(i == 3 and (ans == 'Y' or ans == 'y')):
        flu+=1
    elif(i == 4 and (ans == 'Y' or ans == 'y')):
        c19+=1
    elif(i == 5 and (ans == 'Y' or ans == 'y')):
        flu+=1
        c19+=1
        pneumonia+=1
    elif(i == 6 and (ans == 'Y' or ans == 'y')):
        flu+=1
        c19+=1
        pneumonia+=1
    elif(i == 7 and (ans == 'Y' or ans == 'y')):
        flu+=5
    elif(i == 8 and (ans == 'Y' or ans == 'y')):
        pneumonia+=5
    elif(i == 9 and (ans == 'Y' or ans == 'y')):
        c19+=5

if(flu == 0 and cold == 0 and c19 == 0 and pneumonia == 0):
    print('Congratulations! You are healthy!')
else:
    max_index = 0
    max = -1
    dis = [flu, cold, c19, pneumonia]
    for i in range(4):
        if(dis[i] > max):
            max_index = i
            max = dis[i]
    disease = ''
    if(max_index == 0):
        disease = 'Flu'
    elif(max_index == 1):
        disease = 'Common Cold'
    elif(max_index == 2):
        disease = 'Covid 19'
    elif(max_index == 3):
        disease = 'Pneumonia'
    print('Based on the symptomps, you may have ' + disease + '.')


