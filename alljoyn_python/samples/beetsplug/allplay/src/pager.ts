import { bindingMode } from 'aurelia-binding';
import { bindable } from 'aurelia-templating';
import { LogManager, View, inject, computedFrom } from 'aurelia-framework';

let logger = LogManager.getLogger('pager');

@inject(Element)
export class Pager {
  @bindable({defaultBindingMode: bindingMode.twoWay})
  currentPage : number = 0;
  @bindable items;
  @bindable pageSize : number = 50;
  @bindable showPages = false;
  @bindable showFirst = false;
  @bindable searchText = '';

  goToPage(page) {
    if (page > 0) {
      this.currentPage = page;
    }
  }

  @computedFrom('items', 'pageSize')
  get numberOfVisiblePages() {
      return this.items.length / this.pageSize;
  }

  private match(search : string, item: any) : boolean {
    let lcase_search = this.searchText.toLowerCase();
    if((item['title'].toLowerCase().indexOf(lcase_search) > -1) ||
       (item['artist'].toLowerCase().indexOf(lcase_search) > -1) ||
       (item['album'].toLowerCase().indexOf(lcase_search) > -1)) {
         return true;
    }
    return false;
  }

  onSearchTextChanged() {
    if(this.searchText.length > 0) {
        this.items.filter((item) => this.match(item, this.searchText));
    }
  }

  @computedFrom('currentPage', 'search')
  get selectedItems() {
      
      let start : number = this.pageSize * this.currentPage;
      let end = start + +this.pageSize;
      end = Math.min(this.items.length - this.pageSize, end);
      return this.items.slice(start, end);
  }
}