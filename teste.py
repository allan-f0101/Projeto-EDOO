def malkuth(energianecessaria):
    energiagerada=0
    resultado=False
    print('Hoje é o dia da Malkuth!')
    print('Malkuth: Ah, onde estão meus modos! Malkuth se apresentando!')
    print('Malkuth: Estamos responsáveis hoje por organizar por tamanho nossa lista de funcionários do time de controle, vamos entregar com resultados perfeitos!')
    print()
    nomes=input()

    if nomes=='':
        resultado=False
        print('Malkuth: Pessoal?! Onde está todo mundo?! Isso é inaceitável!')
        print()
    else:
        listanomes=[]
        listanomes=nomes.split()

        for t in range(len(listanomes)-1):
            for i in range(len(listanomes)-1-t):
                A=listanomes[i]
                B=listanomes[i+1]
                if len(A)>len(B):
                    listanomes[i],listanomes[i+1]=listanomes[i+1],listanomes[i]

        energiagerada=(len(listanomes[0])+len(listanomes[len(listanomes)-1]))*20
        print(' '.join(listanomes))
        print(f'Energia Coletada: {energiagerada} / {energianecessaria}')

        if energiagerada>=energianecessaria:
            resultado=True
            print('Malkuth: O treino vespertino de hoje foi um sucesso! Estarei esperando vocês no período noturno, pessoal!')
            print()
        else:
            resultado=False
            print('Malkuth: Ah não.. não conseguimos energia suficiente... amanhã eu dobrarei a carga horária para que a gente possa concluir o expediente com excelência!')
            print()

    return resultado
def yesod():
    print('Hoje é dia do Yesod!')
    print('Yesod: Você é a cabeça dessa corporação, você deve agir como um exemplo para os outros e fazer certeza que esse dia passe coordialmente seguindo as regras.')
    print('Yesod: Hoje estamos com um problema a resolver. Você é um progamador, não é? Hoje recebemos vários caracteres, e você terá de as comprimir para facilitar as informações.')
    print()
    dados=input()
    saida=''
    resultado=True

    if dados[0]=='&':
        saida=''
        resultado=False
    else:
        atual=dados[0]
        contador=1
        i=1

        while i<len(dados) and dados[i]!='&':
            if dados[i]==atual:
                contador=contador+1
            else:
                if contador==1:
                    saida=saida+atual
                else:
                    saida=saida+str(contador)+atual
                atual=dados[i]
                contador=1
            i=i+1

        if contador==1:
            saida=saida+atual
        else:
            saida=saida+str(contador)+atual

        if '&' in dados:
            resultado=False

    if resultado==True:
        print(f"Yesod: Aqui está a lista de caracteres comprimidos: '{saida}'")
        print()
    else:
        print('Yesod: Os caracteres de hoje estavam corrompidas... devemos encerrar o dia mais cedo e investigar.')
        print(f"Yesod: Pelo menos, essas informações ainda estão conosco: '{saida}'")
        print()

    return resultado
def binah(energianecessaria):
    print('Hoje é o dia da Binah.')
    print('Binah: ...Você chegou.')
    print('Binah: Você já deve saber o que fazer. Espero um bom resultado vindo de você.')
    print()
    matriz1=[[0,0,0],[0,0,0],[0,0,0]]
    matriz2=[[0,0,0],[0,0,0],[0,0,0]]
    matrizresultado=[[0,0,0],[0,0,0],[0,0,0]]
    energiagerada=0
    resultado=False
    for l in range(0,3):
        linha=input().split()
        for c in range(0,3):
            matriz1[l][c]=int(linha[c])

    for l in range(0,3):
        linha=input().split()
        for c in range(0,3):
            matriz2[l][c]=int(linha[c])

    for l in range(0,3):
        for c in range(0,3):
            for k in range(0,3):
                matrizresultado[l][c]=matrizresultado[l][c]+matriz1[l][k]*matriz2[k][c]
    for l in range(0,3):
        print(matrizresultado[l])
    print()
    for l in range(0,3):
        energiagerada=energiagerada+matrizresultado[l][l]

    print(f'Energia Coletada: {energiagerada} / {energianecessaria}')

    if energiagerada>=energianecessaria:
        resultado=True
        print('Binah: O expediente foi concluído. Não cometa os mesmos erros amanhã.')
        print()
    else:
        resultado=False
        print('Binah: É realmente uma sensação única te ver falhando...')
        print()

    return resultado


qtdedias=int(input())
print('Hoje é o dia da Lobotomy CinCorporation!')
print()
relatorio=[]
for n in range(qtdedias):
    energianecessaria=100+n*40
    print(f'Angela: Hoje é o dia {n+1} de {qtdedias}. Espero mais um expediente concluído com excelência.')
    sefiro=input()
    if sefiro=='Malkuth':
        resultado=malkuth(energianecessaria)
        relatorio.append(resultado)
    elif sefiro=='Yesod':
        resultado=yesod()
        relatorio.append(resultado)
    elif sefiro=="Binah":
        resultado=binah(energianecessaria)
        relatorio.append(resultado)
    else:
        print('Angela: Essa sefirot não está disponível hoje.')
        print()
        relatorio.append(False)

print('Angela: O relatório dessa semana está pronto.')
for i in range(len(relatorio)):
    if relatorio[i]==True:
        print(f'Dia {i+1} | Status: Energia necessária adquirida.')
    else:
        print(f'Dia {i+1} | Status: Energia necessária não adquirida.')