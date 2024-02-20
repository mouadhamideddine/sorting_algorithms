from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from bs4 import BeautifulSoup

# Define the servers you're interested in
servers = ['HellMina', 'Imagiro', 'Orukam', 'TalKasha', 'Tylezia', 'Draconiros']

# Configure Firefox WebDriver options
options = Options()
options.headless = True  # Run Firefox in headless mode (without GUI)

# Initialize the Firefox WebDriver
driver = webdriver.Firefox(firefox_options=options)  # This line differs from the previous code

# Load the website
url = 'https://www.leskamas.com/en-gb/sell-kamas.html'
driver.get(url)

# Create a BeautifulSoup object to parse the HTML content
soup = BeautifulSoup(driver.page_source, 'html.parser')

# Find the table rows containing the server names and prices
rows = soup.find_all('tr')

# Loop through the rows and extract the prices for the specified servers
for row in rows:
    cells = row.find_all('td')
    if len(cells) >= 2:
        server_name = cells[0].text.strip()
        if server_name in servers:
            price_dh_per_m = cells[6].text.strip()
            price_dh = price_dh_per_m.split('DH/M')[0]
            print(f"{server_name}: {price_dh} DH/M")

# Quit the web driver
driver.quit()