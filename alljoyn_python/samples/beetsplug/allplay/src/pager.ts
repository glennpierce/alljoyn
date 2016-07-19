import { bindingMode } from 'aurelia-binding';
import { bindable } from 'aurelia-templating';
import { LogManager, View, inject, computedFrom } from 'aurelia-framework';

let logger = LogManager.getLogger('pager');

@inject(Element)
export class Pager {
  @bindable({defaultBindingMode: bindingMode.twoWay})
  currentPage : number = 0;
  @bindable items;
  @bindable pageSize : number;
  @bindable showPages = false;
  @bindable showFirst = false;
  @bindable searchText = '';
  @bindable numberOfPages : number;

  goToPage(page) {
    if (page >= 0) {
      this.currentPage = page;
    }
  }

  private match(search : string, item: any) : boolean {
        let lcase_search = search.toLowerCase();
        if((item['title'].toLowerCase().indexOf(lcase_search) > -1) ||
        (item['artist'].toLowerCase().indexOf(lcase_search) > -1) ||
        (item['album'].toLowerCase().indexOf(lcase_search) > -1)) {
            return true;
        }
        return false;
  }

  @computedFrom('currentPage', 'searchText')
  get selectedItems() {
      let start : number = this.pageSize * this.currentPage;
      let end = start + +this.pageSize;
      end = Math.min(this.items.length - this.pageSize, end);
      let filteredItems = this.items.slice();

      if (this.searchText !== undefined && this.searchText !== "")  {
        filteredItems = this.items.filter((item) => this.match(this.searchText, item)); 
      }

      filteredItems = filteredItems.slice(start, end); 
      this.numberOfPages = filteredItems.length / this.pageSize;

      return filteredItems;
  }
}