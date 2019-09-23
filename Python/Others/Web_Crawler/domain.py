from urllib.parse import urlparse


def get_domain_name(url):
    try:
        link = get_subdomain_name(url).split('.')
        domain_name = link[-2] + '.' + link[-1]
        return domain_name
    except:
        return ''


def get_subdomain_name(url):
    try:
        return urlparse(url).netloc
    except:
        return ''

#print(get_domain_name("https://nirav.jain.com/video"))