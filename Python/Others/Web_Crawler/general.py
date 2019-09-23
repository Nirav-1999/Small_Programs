import os

def create_folder(projectname):
    if not os.path.exists(projectname):
        print('Creating directory ' + projectname)
        os.makedirs(projectname)

def create_data_files(projectname,base_url):
    queue_file = os.path.join(projectname + '/queue.txt')
    crawled_file = os.path.join(projectname + '/crawled.txt')
    if not os.path.isfile(queue_file):
        write_to_file(queue_file,base_url)
    if not os.path.isfile(crawled_file):
        write_to_file(crawled_file,'')

def write_to_file(filename,content):
    with open(filename,'w') as f:
        f.write(content)

def append_to_file(filename,content):
    with open(filename,'a') as f:
        f.write(content + '\n')

def delete_file_contents(path):
    with open(path,'w') as f:
        pass

def file_to_set(file):
    results = set()
    with open(file , 'rt') as f:
        for line in f:
            results.add(line.replace('\n',''))
    return results

def set_to_file(links,filename):
    with open(filename , 'w') as f:
        for link in sorted(links):
            f.write(link+'\n')


#create_folder('Nirav')
#write_to_file('abc/crawled.txt','Hello')