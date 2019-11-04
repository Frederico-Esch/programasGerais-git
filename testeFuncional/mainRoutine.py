import os
import sys
import stat
if not os.path.exists('tmp'):
    os.mkdir('tmp')
flag = True
quest = 1
quest_name = ['']
answer = ['']
perg = ['']
ver = '###0.1.6###\n'
leitura = None
try:
    file = open('tmp/resp.txt', 'r')
    leitura = file.readline()
except:
    file = None
if leitura == ver:
    print('você já concluiu o teste!')
    input()

    sys.exit(0)

while flag:
    try:
        # as qst + str(quest)
        quest_name.append("quest" + str(quest))
        # print(quest_name[quest])
        quest_name[quest] = __import__(quest_name[quest])
    except:
        flag = False
    else:
        quest += 1
for i in range(1, quest):
    quest_name[i].question()
    answer.append(quest_name[i].answer())
    perg.append(quest_name[i].perg())
# print(perg[1:])
# print(answer[1:])
if file is not None:
    os.chmod('tmp/resp.txt', stat.S_IRWXU)
file = open('tmp/resp.txt', 'w')
file.write(ver)
for i in range(1, quest):
    file.write(perg[i] + '\n' + str(answer[i]) + '\n')
file.close()
os.chmod('tmp/resp.txt', stat.S_IREAD)
