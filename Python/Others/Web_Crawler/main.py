import threading
from queue import Queue
from general import *
from linkfinder import *
from domain import *
from spider import Spider

project_name = input("Enter Project-Name : ")
base_url = input("Enter the start url : ")
NO_OF_THREADS= 4
domain_name = get_domain_name(base_url)
QUEUE_FILE = project_name + '/queue.txt'
CRAWLED_FILE = project_name + '/crawled.txt'
queue = Queue()
Spider(project_name,base_url,domain_name)

def create_workers():
    for _ in range(NO_OF_THREADS):
        t = threading.Thread(target=work)
        t.daemon = True
        t.start()

    
def work():
    while True:
        url = queue.get()
        Spider.crawl_page(threading.current_thread().name,url)
        queue.task_done()


def create_jobs():
    for link in file_to_set(QUEUE_FILE):
        queue.put(link)
    queue.join()
    crawl()
    


def crawl():
    queued_links = file_to_set(QUEUE_FILE)
    if len(queued_links) > 0:
        print(str(len(queued_links)) + ' links in the queue')
        create_jobs()




create_workers()
crawl()