'''
Author: Abhishek Goyal

LeetCode Scraper is a python program that logins into your LeetCode account, and copies your code for your solved 
problems into its corresponding file.

For example, your solution to the problem <name> will be stored in the file <name>.cpp
'''

TIME_DELAY = 10
import os
import time
import json
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.common.action_chains import ActionChains
import pyperclip

chrome_options = Options()
chrome_options.add_argument('--log-level=3')
driver = webdriver.Chrome(options=chrome_options)
driver.implicitly_wait(TIME_DELAY)

def get_solved_problems():
    driver.get(driver.current_url + '/practice/')
    xpaths = ['//*[@id="School"]', '//*[@id="Basic"]', '//*[@id="Easy"]', '//*[@id="Medium"]', '//*[@id="Hard"]']
    problems = {}
    for i, xpath in enumerate(xpaths):
        driver.find_element_by_xpath(f'//*[@id="problem-solved-div"]/a[{i+1}]').click()
        li_a = driver.find_element_by_xpath(xpath).find_elements_by_tag_name('a')
        problems.update({a.text : a.get_attribute('href') for a in li_a})
    return problems

def sign_into_geeksforgeeks(username, password):
    driver.get('https://auth.geeksforgeeks.org/')
    driver.find_element_by_xpath('//*[@id="luser"]').send_keys(username)
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(password)
    driver.find_element_by_xpath('//*[@id="password"]').send_keys(Keys.ENTER)

if __name__ == '__main__':
    sign_into_geeksforgeeks(username='abhishek_g0yal', password='cKGRg$Niap#yBm9')
    input('proceed?')
    solved_problems = get_solved_problems()
    with open('solved_problems.json', 'w') as f:
        json.dump(solved_problems, f, indent=4)
    # save_codes(submissions_to_save, path='./GeeksforGeeks/')
    driver.close()