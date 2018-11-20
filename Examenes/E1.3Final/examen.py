from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver import ActionChains
import time
browser = webdriver.Chrome()

browser.get('http://10.49.71.125:3000/~certificatec/pronosticos')
matricula = {}
nombre = {}
link = {}
alumons_td = {}
browser.find_element_by_xpath('//*[@id="login_username"]').send_keys('ariel.garcia@itesm.mx');
browser.find_element_by_xpath('//*[@id="login_password"]').send_keys('1234');
browser.find_element_by_xpath('//*[@id="login_submit"]').click();
time.sleep(1)
browser.find_element_by_xpath('//*[@id="nav"]/div/ul/li[7]/a').click();
time.sleep(1)
browser.find_element_by_xpath('//*[@id="sidebar"]/ul[1]/li[5]/a').click();
time.sleep(1)
alumnos_table = browser.find_element_by_xpath('//*[@id="candidatos_container"]/tbody');
alumons_row = alumnos_table.find_elements_by_tag_name('tr');
for i in range(0, len(alumons_row)):
    alumons_td[i] = alumons_row[i].find_elements_by_tag_name('td')
    matricula[i] = alumons_td[i][0].text
    nombre[i] = alumons_td[i][1].text
    print(matricula[i], nombre[i])

materias_alumno ={}
codigo_alumno = {}
for i in range(0, len(alumons_row)):
    browser.find_element_by_xpath('//*[@id="candidatos_container"]/tbody/tr['+str(i+1)+']/td[1]/a').click()
    time.sleep(1)
    browser.find_element_by_xpath('//*[@id="sidebar"]/ul[1]/li[3]/a').click();
    time.sleep(1)

    materias_table = browser.find_element_by_xpath('//*[@id="pronosticos_container"]/tbody');
    materias_row = materias_table.find_elements_by_tag_name('tr');
    for j in range(0, len(materias_row )):
        td2 = materias_row[j].find_elements_by_tag_name('td')
        codigo_alumno[j] = td2[0].text
        materias_alumno[j] = td2[1].text

    with open('csvfile.csv','a') as file:
        for j in range(0, len(materias_row )):
            file.write(matricula[i]+',')
            file.write(nombre[i]+',')
            file.write(codigo_alumno[j]+',')
            file.write(materias_alumno[j])
            file.write('\n')


    browser.back()
    browser.back()
    time.sleep(2)
